#include <bits/stdc++.h>
using namespace std;
vector<int> ar[100001];
int dist[100001];
int vis[100001];
int level[100001];
void bfs(int node)
{
    dist[node] = 0;
    vis[node] = 1;
    level[dist[node]]++;
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
                level[dist[child]]++;
                q.push(child);
            }
        }
    }
}

int main()
{
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
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < 100001; i++)
            dist[i] = 0, vis[i] = 0, level[i] = 0;
        bfs(x);
        cout << level[y] << endl;
    }
    return 0;
}

//testcase
// 9 10
// 1 2
// 2 3
// 1 7
// 2 4
// 3 4
// 4 7
// 7 8
// 9 7
// 7 6
// 5 6
// 3
// 4 2
// 5 3
// 2 1
