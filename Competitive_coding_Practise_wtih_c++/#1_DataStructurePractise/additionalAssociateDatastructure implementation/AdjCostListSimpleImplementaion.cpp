#include <bits/stdc++.h>
using namespace std;
void addEadge(vector<pair<int, int>> graph[], int u, int v, int w)
{
    graph[u].push_back(make_pair(v, w)); //from here your concept of empalce is cleared
    graph[v].emplace_back(u, w);
    // graph[u].emplace_back(v, w);
}
void printGraph(vector<pair<int, int>> graph[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << "\n Adjancency list of vertex :" << i << " " << endl;

        for (auto j : graph[i])
            cout << "-->" << j.first << "(" << j.second << ")"
                 << " ";
    }
    cout << endl;
}
void dfs(vector<pair<int, int>> graph[], int i, int V, vector<bool> &visited)
{
    cout << i << " ";
    visited[i] = true;
    for (int j = 0; j < V; j++)
        if (!visited[j] && graph[i][j].first)
            dfs(graph, j, V, visited);
}
int main()
{
    int V = 6;
    vector<pair<int, int>> gp[6];
    vector<bool> visited(V, false);
    addEadge(gp, 0, 1, 25);
    addEadge(gp, 0, 4, 32);
    addEadge(gp, 1, 2, 23);
    addEadge(gp, 1, 3, 43);
    addEadge(gp, 1, 1, 72);
    addEadge(gp, 2, 5, 12);
    addEadge(gp, 3, 4, 32);
    addEadge(gp, 4, 2, 21);
    addEadge(gp, 4, 1, 9);
    addEadge(gp, 5, 2, 61);
    addEadge(gp, 5, 1, 23);
    printGraph(gp, 6);
    cout << "dfs :";
    dfs(gp, 1, V, visited);

    // cout << gp[1][2].first << endl;
    return 0;
}