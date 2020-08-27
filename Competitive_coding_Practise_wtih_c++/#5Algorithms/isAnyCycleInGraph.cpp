#include <bits/stdc++.h>
using namespace std;
vector<int> ar[1001];
int vis[1001];
bool hasCycle(int node, int par)
{
    vis[node] = 1;
    for (int child : ar[node])
    {
        if (!vis[child])
        {
            if (hasCycle(child, node) == true) // only  propagation of result
                return true;
        }
        else
        {
            if (child != par) // avoid only parent
                return true;
        }
    }
    return false;
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
    hasCycle(1, -1) ? cout << "Yes" << endl : cout << "noCycle" << endl;

    return 0;
}

// this  program to print the all bridge in different component of graph;
// 5 5
// 1 2
// 2 3
// 3 4
// 4 5
// 5 2
