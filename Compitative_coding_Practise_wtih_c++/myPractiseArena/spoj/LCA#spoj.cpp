#include <bits/stdc++.h>
using namespace std;
void sahu()
{
#ifndef MY_OFFLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !MY_OFFLINE_JUDGE
}
vector<int> ar[1010];
int dist[1010];
int vis[1010];
int par[1010];
int lca[1010][int(log2(1010))];
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // sahu();
    int t;
    cin >> t;
    int case_no = 1;
    while (t--)
    {
        // firstly clear everything
        for (int i = 0; i < 1010; i++)
        {
            dist[i] = 0, vis[i] = 0, par[i] = 0;
            for (int j = 0; j < log2(1010); j++)
                lca[i][j] = 0;
        }
        // take input properly
        cin >> n;
        maxN = log2(n);
        for (int i = 1; i <= n; i++)
        {
            int m, a = i, b;
            cin >> m;
            while (m--)
            {
                cin >> b;
                ar[a].push_back(b), ar[b].push_back(a);
            }
        }
        // preprocessing
        bfs(1, -1);
        buildTable();

        cout << "Case " << case_no++ << ":" << endl;
        // processing querry
        int q, a, b;
        cin >> q;
        while (q--)
        {
            cin >> a >> b;
            cout << lowestCommonAncestor(a, b) << endl;
        }
    }
    return 0;
}
//test case

// 1
// 7
// 3 2 3 4
// 0
// 3 5 6 7
// 0
// 0
// 0
// 0
// 2
// 5 7
// 2 7

//Answer
// Case 1:
// 3
// 1

// this solution fails  if in the given tree root is other than 1 ;
// check my next solution in same directory which is independent of root ;