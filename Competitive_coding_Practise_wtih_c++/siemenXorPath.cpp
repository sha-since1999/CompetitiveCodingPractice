#include <bits/stdc++.h>
//#include "sahu.h"
using namespace std;
typedef long long ll;
int ans = 0;
void dfs(int cur, int par, int Xor, int x, int *w, vector<int> vis, vector<int> *gph)
{
    Xor ^= w[cur];
    if (Xor == x)
    {
        ans++;
        return;
    }
    if (cur == par)
        return;
    vis[cur] = 1;
    for (int ch : gph[cur])
    {
        if (vis[cur] != 1)
            dfs(ch, par, Xor, x, w, vis, gph);
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, x;
        cin >> n;
        int w[n];
        vector<int> gph[n];
        for (int i = 0; i < n; i++)
            cin >> w[i];
        cin >> x;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            gph[u].push_back(v);
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                vector<int> vis(n + 1, 0);
                dfs(i, j, w[i], x, w, vis, gph);
            }
        }

        cout << ans << endl;
        ans = 0;
    }
    return 0;
}

// 1
// 5
// 2 1 3 1 1
// 1
// 1 2
// 1 3
// 3 4
// 3 5
