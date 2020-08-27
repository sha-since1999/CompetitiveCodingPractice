#include <bits/stdc++.h>
using namespace std;
vector<int> ar[100010];
int dist[100010];
int vis[100010];
int par[100010];
void bfs(int node, int p)
{
    dist[node] = 1;
    vis[node] = 1;
    par[node] = -1;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int child : ar[curr])
        {
            if (!vis[child])
            {
                vis[child] = 1;
                dist[child] = dist[curr] + 1;
                par[child] = curr;
                q.push(child);
            }
        }
    }
}
void sahu()
{
#ifndef MY_OFFLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !MY_OFFLINE_JUDGE
}

int main()
{
    // sahu();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b), ar[b].push_back(a);
    }
    bfs(1, -1);

    if (!vis[n])
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << dist[n] << endl;
        vector<int> path;
        while (par[n] != -1)
            path.push_back(n), n = par[n];
        path.push_back(n);

        for (auto i = path.rbegin(); i < path.rend(); i++)
            cout << *i << " ";
    }
    cout << endl;
    return 0;
}
