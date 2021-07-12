#include <bits/stdc++.h>
#include "input.h"

using namespace std;
int n;
vector<int> vis;
static unordered_map<int, int> mp[100001];
int dfs(int s, int d)
{
    if (s == d)
        return 0;
    vis[s] = 1;

    int mn = INT32_MAX;
    for (auto m : mp[s])
    {
        // cout << m.first << " ";
        int x;
        if (vis[m.first] == 0)
            x = dfs(m.first, d) + m.second;
        mn = min(mn, x);
    }
    return mn;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int e;
    cin >> n >> e;
    set<int> st;
    for (int i = 0; i < e; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        st.insert(x);
        st.insert(y);
        mp[x][y] = t;
        mp[y][x] = t;
    }

    int r;
    cin >> r;
    vector<int> rr(r);
    for (int i = 0; i < r; i++)
    {
        int x;
        cin >> rr[i];
    }

    for (int s : st)
    {
        int mn = INT32_MAX;
        for (int x : rr)
        {
            vis.assign(n, 0);
            int df = dfs(s, x);
            vis.clear();
            if (df >= 0)
                mn = min(df, mn);
        }
        cout << mn << endl;
    }
    return 0;
}
