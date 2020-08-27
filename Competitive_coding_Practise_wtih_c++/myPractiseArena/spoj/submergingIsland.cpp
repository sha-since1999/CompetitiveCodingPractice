#include <bits/stdc++.h>
using namespace std;
vector<int> ar[10001];
int vis[10001];
int low[10001];
int in[10001];
int timer = 1;
set<int> ap;
void dfs(int node, int par)
{
    vis[node] = 1;
    low[node] = in[node] = timer++;
    int count_child = 0;
    for (int child : ar[node])
    {
        if (child == par)
            continue;

        if (vis[child])
        { // this would be BACK EADGE
            low[node] = min(low[node], in[child]);
        }
        else
        { // this would be FORWARD EADGE
            dfs(child, node);
            low[node] = min(low[node], low[child]);
            if (in[node] <= low[child] and par != -1)
                ap.insert(node);
            count_child++;
        }
        if (par == -1 and count_child > 1)
            ap.insert(child);
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    while (v or e)
    {
        for (int i = 0; i < 10001; i++)
            ar[i].clear(), low[i] = 0, in[i] = 0, vis[i] = 0;
        ap.clear();

        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            ar[a].push_back(b), ar[b].push_back(a);
        }
        for (int i = 0; i <= v; i++)
        {
            if (!vis[i])
                dfs(i, -1);
        }

        cout << ap.size() << endl;

        cin >> v >> e;
    }
    return 0;
}
//test case
// 3 3
// 1 2
// 2 3
// 1 3
// 6 8
// 1 3
// 6 1
// 6 3
// 4 1
// 6 4
// 5 2
// 3 2
// 3 5
// 0 0