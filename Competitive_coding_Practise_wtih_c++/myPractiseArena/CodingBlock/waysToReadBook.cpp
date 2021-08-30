#include <bits/stdc++.h>
#include "input.h"
typedef long long ll;
const int mod = 1e9 + 7;
using namespace std;
ll Mod(ll n)
{
    n %= mod;
    if (n < 0)
        n += mod;
    return n;
}
int ncr(int n, int r)
{
    if (n == r or r == 0)
        return 1;
    return ncr(n - 1, r - 1) + ncr(n - 1, r);
}
ll ways(ll n)
{
    ll ans = 0;
    int x = n / 2;
    if (n & 1)
        x = n / 2 + 1;
    int i = 0;
    while (n >= x)
    {
        ans += ncr(n, i);
        ans = Mod(ans);
        n--;
        i++;
    }

    return ans;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << ways(n) << endl;
    }

    return 0;
}
