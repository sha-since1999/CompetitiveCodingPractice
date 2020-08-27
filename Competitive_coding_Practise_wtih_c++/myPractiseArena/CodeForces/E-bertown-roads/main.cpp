#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;
int n = 0, m = 0;
bool has_bridge = false;
int timer;
int vis[100001];
int low[100001];
int in[100001];
vector<pair<int, int>> edges;
vector<int> ar[100001];
void dfs(int node, int par)
{
    vis[node] = 1;
    low[node] = in[node] = timer++;
    for (int child : ar[node])
    {
        if (child == par)
            continue;
        if (vis[child])
        {
            low[node] = min(low[node], in[child]);
            if (in[child] < in[node])
                edges.push_back({node, child});
        }
        else
        {
            dfs(child, node);
            if (in[node] < low[child])
            {
                has_bridge = true;
                return;
            }
            edges.push_back({node, child});
            low[node] = min(low[node], low[child]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    dfs(1, -1);
    if (!has_bridge)
    {
        for (auto e : edges)
            cout << e.first << " " << e.second << endl;
    }
    else
        cout << 0 << endl;
    return 0;
}
