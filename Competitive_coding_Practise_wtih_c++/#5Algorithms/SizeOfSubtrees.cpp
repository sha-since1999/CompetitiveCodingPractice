#include <bits/stdc++.h>
using namespace std;
vector<int> ar[1001];
int vis[1001];
int subtreeSize[1001];
int dfs(int node) //O(n)
{
    vis[node] = 1;
    int curr_size = 1;
    for (int child : ar[node])
    {
        if (!vis[child])
        {
            curr_size += dfs(child);
        }
    }
    subtreeSize[node] = curr_size;

    return curr_size;
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
    dfs(1);
    // here we can print size of  specific node
    for (int i = 1; i <= v; i++)
        cout << subtreeSize[i] << " ";
    return 0;
}

// this  program to print the all bridge in different component of graph;
// 6 5
// 1 2
// 2 3
// 2 4
// 4 5
// 4 6
