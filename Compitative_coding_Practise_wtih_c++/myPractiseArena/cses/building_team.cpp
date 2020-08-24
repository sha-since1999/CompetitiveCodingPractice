#include <bits/stdc++.h>
using namespace std;
vector<int> ar[100010];
int vis[100010] = {0};
int color[100010];
bool posible = true;
void dfs(int node, int c) //  correct
{
    if (!posible)
        return;
    vis[node] = 1;
    color[node] = c;
    for (int child : ar[node])
    {
        if (!vis[child])
            dfs(child, c ^ 1);

        else if (color[node] == color[child])
            posible = false;
    }
}
void sahu()
{
#ifndef MY_OFFLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !MY_OFFLINE_JUDGE
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
    }
    for (int i = 1; i <= n; i++)
        color[i] = -1;

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, 0);

    if (posible)
    {
        for (int i = 1; i <= n; i++)
            color[i] ? cout << 2 << " " : cout << 1 << " ";
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
