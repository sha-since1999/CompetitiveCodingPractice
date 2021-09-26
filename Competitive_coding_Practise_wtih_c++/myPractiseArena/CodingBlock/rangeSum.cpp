#include <bits/stdc++.h>
#include "input.h"
using namespace std;
#define ll long long int
const ll mod = 10e9 + 7;
ll Mod(ll x)
{
    x %= mod;
    if (x < 0)
        x += mod;
    return x;
}
int distinctDigit(ll x)
{

    set<ll> s;
    while (x > 0)
    {
        int d = x % 10;
        x /= 10;
        s.insert(d);
    }

    return s.size();
}
int main()
{

    ll a, b, k;
    cin >> a >> b >> k;
    ll sum = 0;
    for (ll i = a; i <= b; i++)
    {
        if (distinctDigit(i) > k)
        {
            sum = sum + i;
            sum = Mod(sum);
        }
    }
    cout << sum << endl;
    return 0;
}
