#include <bits/stdc++.h>
using namespace std;
void sahu()
{
#ifndef MY_OFFLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !MY_OFFLINE_JUDGE
}
vector<int> ar[100010];
int dist[100010];
int vis[100010];
int par[100010];
int lca[int(log2(100010))][int(log2(100010))];
int n, maxN;

void bfs(int node, int p)
{
    dist[node] = 1;
    vis[node] = 1;
    par[node] = -1;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int child : ar[curr])
        {
            if (!vis[child])
            {
                vis[child] = 1;
                dist[child] = dist[curr] + 1;
                par[child] = curr;
                q.push(child);
            }
        }
    }
}
int lowestCommonAncestor(int a, int b)
{
    if (dist[b] < dist[a])
        swap(a, b);
    int d = dist[b] - dist[a];
    while (d)
    {
        int i = log2(d);
        b = par[b];
        d -= (1 << i);
    }
    if (a == b)
        return a;
    int j = maxN;
    while (j--)
    {
        if (lca[a][j] != -1 and lca[a][j] != lca[b][j])
            a = lca[a][j], b = lca[b][j];
    }
    return par[a];
}

void buildTable()
{
    for (int j = 0; j <= maxN; j++)
        for (int i = 1; i <= n; i++)
        {
            if (j == 0)
                lca[i][j] = par[i]; // initialise 0 th par of node;
            else if (lca[i][j - 1] != -1)
            {
                int par = lca[i][j - 1]; //  j-1  th par ,j-1 th par of i;
                lca[i][j] = lca[par][j - 1];
            }
        }
}
int main()
{
    // sahu();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, a, b, root = 1;
    cin >> n >> m;
    maxN = log2(n);
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        ar[a].push_back(b), ar[b].push_back(a);
    }
    cin >> a >> b;
    bfs(root, -1);
    buildTable();
    cout << lowestCommonAncestor(a, b) << endl;
    return 0;
}

// notes it limitations : it will fail if root correct root is not given to it