#include <bits/stdc++.h>
using namespace std;

int vis[10001] = {0};
int dist[10001] = {0};
vector<int> ar[10001];
void bfs(int v)
{
    queue<int> q;
    vis[v] = 1;
    dist[v] = 0;
    q.push(v);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int child : ar[curr])
        {
            if (!vis[child])
            {
                dist[child] = dist[curr] + 1;
                vis[child] = 1;
                q.push(child);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ar[x].push_back(y), ar[y].push_back(x);
    }
    bfs(1);
    // for(int i=1;i<=n;i++)cout<<dist[i]<< " ";
    int q;
    cin >> q;
    int id = -1, mindist = INT_MAX;
    while (q--)
    {
        int g;
        cin >> g;
        if (dist[g] == mindist and g < id)
            id = g;
        if (dist[g] < mindist)
            mindist = dist[g], id = g;
    }
    cout << id << endl;
    return 0;
}
//testcase
// 6
// 1 2
// 1 3
// 1 4
// 2 5
// 2 6
// 4
// 5
// 6
// 3
// 4