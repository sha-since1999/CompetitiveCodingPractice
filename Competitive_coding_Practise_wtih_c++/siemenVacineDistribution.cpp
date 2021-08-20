#include <bits/stdc++.h>
#include "input.h"
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll n, m;
        cin >> n >> m;
        map<int, int, greater<int>> mp;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        int ans = INT32_MAX;
        int mx = ans;
        int cnt = m;
        int mxcnt = 0;

        while (1)
        {
            mx = (mp.begin())->first;
            if (cnt >= n)
            {
                ans = mx;
                break;
            }
            mxcnt = mp[mx];
            cnt += mxcnt;
            mp.erase(mx);
            mp[(mx + 1) / 2] += mxcnt;
            mp[mx / 2] += mxcnt;
        }

        cout << ans << endl;
    }
    return 0;
}

// 2
// 8 5 
// 4 6 9 3 2
// 7 5
// 7 1 7 4 4 