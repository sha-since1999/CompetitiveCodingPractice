#include <bits/stdc++.h>
using namespace std;
vector<int> ar[10001];
int vis[10001];
int dist[10001];
void bfs(int node)
{
    vis[node] = 1;
    dist[node] = 0;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int child : ar[curr])
            if (!vis[child])
            {
                vis[child] = 1;
                dist[child] = dist[curr] + 1;
                q.push(child);
            }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 10001; i++)
            ar[i].clear(), dist[i] = 0, vis[i] = 0;

        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            ar[a].push_back(b), ar[b].push_back(a);
        }

        bfs(1);
        cout << dist[n] << endl;
    }
    return 0;
}

//testcase
// 2
// 3 2
// 1 2
// 2 3
// 4 4
// 1 2
// 2 3
// 3 4
// 4 2