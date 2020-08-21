#include <bits/stdc++.h>
using namespace std;
vector<int> ar[1001];
int vis[1001];
int low[1001];
int in[1001];
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

    for (int i : ap)
        cout << "AP :" << i << " " << endl;
    return 0;
}

// this  program to print the all bridge in different component of graph;

// 8 7
// 1 2
// 4 2
// 2 5
// 4 7
// 5 7
// 5 8
// 3 5
