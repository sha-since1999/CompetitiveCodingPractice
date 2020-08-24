#include <bits/stdc++.h>
using namespace std;
vector<int> ar[1001];
int vis[1001] = {0};
int color[1001];
bool dfs(int node, int c) //  correct
{
    vis[node] = 1;
    color[node] = c;
    for (int child : ar[node])
    {
        if (!vis[child])
        {
            if (dfs(child, c ^ 1) == false)
                return false;
        }
        else
        {
            if (color[child] == color[node])
                return false;
        }
    }
    return true;
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
    for (int i = 0; i < 1001; i++)
        color[i] = -1;

    for (int i = 1; i <= v; i++)
        if (!vis[i])
            cout << dfs(i, 0) << endl;

    return 0;
}

// this  program to print the all bridge in different component of graph;

//notes odd length  cycle can make bipartite graph
// in this two cycle  ol length 3 and 4
//test case
// 8 8
// 1 2
// 4 2
// 2 6
// 4 7
// 7 6
// 5 8
// 3 5
// 8 3