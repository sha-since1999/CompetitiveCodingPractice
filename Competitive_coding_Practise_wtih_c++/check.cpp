
#include "bits/stdc++.h"
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define vpipii vector<pipii>
#define vpiipi vector<piipi>
#define pb push_back
#define pob pop_back
#define pii pair<int, int>
#define pipii pair<int, pii>
#define piipi pair<pii, int>
#define pld pair<long double, long double>
#define mod 1000000007
// #define mod 1000000009
// #define mod 163577857
// #define mod 998244353
#define rep(i, n) for (int i = 0; i < n; i++)
#define repp(i, a, b) for (int i = a; i < b; i++)
#define reppr(i, a, b) for (int i = a - 1; i >= b; i--)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define ff first
#define ss second
#define pc putchar_unlocked
#define gc getchar_unlocked
#define inf 9223372036854775807
#define infn -9223372036854775807
#define pi 3.14159265358979323846
#define eps 0.0000000001
#define sp << " " <<
#define setprec(x) cout << fixed << setprecision(x);
#define REVERSE(a) reverse(all(a));
#define SORT(a) sort(all(a));
#define all(n) n.begin(), n.end()
//GCD and LCM
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

//Modular Exponentiation
int powmod(int x, int y)
{
    if (y == 0)
        return 1;
    int p = powmod(x, y / 2) % mod;
    p = (p * p) % mod;
    return (y % 2 == 0) ? p : (x * p) % mod;
}

//Modular Inverse
int inverse(int a)
{
    return powmod(a, mod - 2);
}

//Binomial Coefficients
const int limbin = 500001;
int fact[limbin], factinv[limbin], coefficientflag = 0;
void Util_nCr()
{
    fact[0] = 1, factinv[0] = 1;
    repp(i, 1, limbin)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        factinv[i] = (factinv[i - 1] * inverse(i)) % mod;
    }
}
int nCr(int n, int r)
{
    if (!coefficientflag)
        coefficientflag = 1, Util_nCr();
    if (n < r)
        return 0;
    return ((fact[n] * inverse(fact[n - r]) % mod * inverse(fact[r])) % mod);
}

// STRING HASHING
int hprime = 31, hmod = 1000000009;
int stringhash(string s)
{
    int res = 0;
    for (auto i : s)
        res = (res * hprime % hmod + (i - 'a')) % hmod;
    return res;
}
vector<int> hashoflen(string s, int k)
{
    int l = s.length();
    vector<int> ans(l - k + 1);
    ans[0] = stringhash(s.substr(0, k));
    int hell = 1, tm = k - 1;
    while (tm--)
        hell = (hell * hprime) % hmod;
    for (int i = k; i < l; i++)
        ans[i - k + 1] = ((ans[i - k] - hell * (s[i - k] - 'a') % hmod + hmod) % hmod * hprime % hmod + (s[i] - 'a')) % hmod;
    return ans;
}
vector<int> prefixhash(string s)
{
    int l = s.length();
    vector<int> hash(l + 1);
    hash[0] = 0;
    rep(i, l)
        hash[i + 1] = (hash[i] * hprime % hmod + (s[i] - 'a')) % hmod;
    return hash;
}
vector<int> suffixhash(string s)
{
    int l = s.length();
    vector<int> hash(l + 1);
    hash[0] = 0;
    int pprime = 1;
    rep(i, l)
        hash[i + 1] = (hash[i] + (s[l - i - 1] - 'a') * pprime % hmod) % hmod,
                 pprime %= hmod;
    ;
    return hash;
}

void solve();
signed main()
{
// ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    rep(i, t)
    {
        // cout< < "Case #" << i+1 << ": ";
        solve();
    }
}
void solve()
{
    int n;
    cin >> n;
    int count = 0, temp = 0;
    vector<int> v;
    rep(i, n)
    {
        cin >> temp;
        if (temp == 0)
            count++;
        else if (count != 0)
            v.pb(count), count = 0;
    }
    if (count != 0)
        v.pb(count);
    SORT(v);
    if (v.size() == 0)
        cout << "No\n";
    else if (v.size() == 1)
    {
        if (v.back() % 2 == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
    {
        int x = v.back();
        if (x % 2 == 0)
        {
            cout << "No\n";
            return;
        }
        v.pop_back();
        int y = v.back();
        if ((x + 1) / 2 > y)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

/* TERMINAL COMMANDS : 

    g++ file.cpp
    ./a.out < input.txt > output.txt
    time ./a.out ( TIME TAKEN )

*/
