#include <bits/stdc++.h>
using namespace std;
vector<int> ar[1000001];
int vis[1000001];
int cc[1000001];
int cc_size = 0;
void dfs(int node)
{
    vis[node] = 1;
    cc[node] = cc_size;
    for (int child : ar[node])
    {
        if (!vis[child])
            dfs(child);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < 1000001; i++)
            ar[i].clear(), vis[i] = 0, cc[i] = 0;
        vector<pair<int, int>> eadge_list;
        for (int i = 0; i < m; i++)
        {
            string op;
            int a, b;
            cin >> a >> op >> b;
            if (op == "=")
                ar[a].push_back(b), ar[b].push_back(a);
            else
            {
                eadge_list.push_back({a, b});
            }
        }
        cc_size = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                cc_size++, dfs(i);
        }
        bool flag = 1;
        for (pair<int, int> p : eadge_list)
        {
            if (cc[p.first] == cc[p.second])
            {
                flag = 0;
                break;
            }
        }
        flag ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}

///testcase
// 2
// 2 2
// 1 = 2
// 1 != 2
// 3 2
// 1 = 2
// 2 != 3
