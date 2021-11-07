#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, int>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    vector<pair<int, int>> res;
    sort(v.begin(), v.end(), cmp);
    int a = v[0].first;
    int b = v[0].second;
    for (auto x : v)
    {
        if (x.first > b)
        {
            res.push_back({a, b});
            a = x.first;
            b = x.second;
        }
        if (x.first <= b)
            b = max(b, x.second);
    }
    res.push_back({a, b});
    for (auto x : res)
        cout << x.first << " " << x.second << endl;
    return 0;
}

// 4
// 1 3
// 2 4
// 2 5
// 7 8

// o/p
// 1 5
// 7 8
