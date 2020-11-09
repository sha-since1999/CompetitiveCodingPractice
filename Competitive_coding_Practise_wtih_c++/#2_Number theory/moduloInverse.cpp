#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll power(ll b, ll a, ll m) // here b for base
{
    ll res = 1;
    while (a)
    {
        if (a % 2)
            res = (res * b) % m, a--;
        else
            b = (b * b) % m, a /= 2;
    }
    return res;
}
int Mod(int x)
{
    x %= mod;
    if (x < 0)
        x += mod;
    return x;
}
ll moduloInverse2(ll a, ll m) // for this method m should be prime
{
    if (gcd(a, m) != 1)
        return -1; //bec no should be coprime for this algo and for having modulo inverse
    return power(a, m - 2, m);
}

ll moduloInverse1(ll a, ll m) //simple method a*x=1(mod m)
{
    ll temp, i = 1;
    if (gcd(a, m) != 1)
        return -1;
    while (temp != 1)
        temp = ((a % m) * (i % m)) % m, i++;
    return i - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, m; //for under modulo m
        cin >> a >> m;

        cout << moduloInverse1(a, m) << endl;

        cout << moduloInverse2(a, m) << endl; //optimized fastest;
    }

    return 0;
} //well tested
