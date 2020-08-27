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
int lowestCommonAncestor(int a, int b)
{
    if (dist[b] < dist[a])
        swap(a, b);
    int d = dist[b] - dist[a];
    while (d--)
        b = par[b];
    if (a == b)
        return a;
    while (par[a] != par[b])
        a = par[a], b = par[b];
    return par[a];
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

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        ar[a].push_back(b), ar[b].push_back(a);
    }
    cin >> a >> b;
    bfs(1, -1);
    cout << lowestCommonAncestor(a, b) << endl;
    return 0;
}
