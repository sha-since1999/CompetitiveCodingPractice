#include <bits/stdc++.h>
#include "input.h" ssa
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

ll Mod(ll x)
{
    x %= mod;
    if (x < 0)
        x += mod;
    return x;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll ans = 1;
        ll h[26] = {0};
        for (char c : s)
            h[c - 'a']++;
        for (ll x : h)
        {
            if (x > 0)
            {
                ans = Mod(ans * x);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
