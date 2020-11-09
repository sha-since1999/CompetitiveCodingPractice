#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll n, m, ans = 0;
        cin >> n >> m;
        for (ll i = n; i <= m; i++)
        {
            stringstream ss;
            ss << i;
            string s;
            ss >> s;
            ll cnt2 = count(s.begin(), s.end(), '2');
            ll cnt3 = count(s.begin(), s.end(), '3');
            ll cnt5 = count(s.begin(), s.end(), '5');
            ll cnt7 = count(s.begin(), s.end(), '7');
            if (cnt2 >= cnt3 and cnt3 >= cnt5 and cnt5 >= cnt7)
                ans++;
        }

        cout << ans % MOD << endl;
    }
    return 0;
}