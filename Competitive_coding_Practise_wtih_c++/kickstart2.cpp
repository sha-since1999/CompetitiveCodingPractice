#include <bits/stdc++.h>
#include "input.h"
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin >> T;
    int cs = 1;
    while (T--)
    {
        ll n, c;
        cin >> n >> c;
        ll l, r;
        vector<pair<int, int>> v;
        ll mr, ml;
        for (int i = 0; i < n; i++)
        {
            cin >> l >> r;
            v.emplace_back(l, r);
            if (l > ml)
                ml = l;
            if (mr < r)
                mr = r;
        }
        vector<int> vcnt;
        ll ans = n;
        for (int i = ml; i <= mr; i++)
        {
            int cnt = 0;
            for (auto x : v)
            {
                if (i > x.first and i < x.second)
                {
                    // cout << i << endl;
                    cnt++;
                }
            }
            vcnt.push_back(cnt);
        }

        sort(vcnt.begin(), vcnt.end(), greater<int>());

        for (int i = 0; i < c; i++)
        {

            ans += vcnt[i];
        }

        cout << "Case #" << cs++ << ": " << ans << endl;
    }
    return 0;
}