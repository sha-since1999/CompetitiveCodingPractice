#include <bits/stdc++.h> // this  program is not completed yet
using namespace std;
void sahu()
{
#ifndef MY_OFFLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !MY_OFFLINE_JUDGE
}
vector<int> ar[100010];
int vis[100010];
int par[100010];
vector<int> path;
int cy = 0;
bool possible;
void dfs(int node, int p) //  correct
{
    par[node] = p;
    vis[node] = 1;
    for (int child : ar[node])
    {
        if (child == p)
            continue;
        if (!vis[child])
            dfs(child, node);
        else
        {
            par[child] = node;
            possible = true;
            cy = child;
        }
    }
}
int main()
{
    // sahu();
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b), ar[b].push_back(a);
        par[i] = -1;
    }
    possible = false;
    dfs(1, -1);
    if (possible)
    {
        path.push_back(cy);
        int city = 1;
        int x = par[cy];
        while (x != cy)
            path.push_back(x), x = par[x], city++;
        path.push_back(x), city++;
        cout << city << endl;
        for (int x : path)
            cout << x << " ";
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
