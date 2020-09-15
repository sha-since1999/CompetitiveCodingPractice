#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked()
#define pc(c) putchar_unlocked(c);
#define forn(i, n) for (i = 0; i < n; i++)
#define fork(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long int
#define si(x) scanf("%d ", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define sv(v) forn(i, n) si(z), v.pb(z)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define sz(a) a.size()
#define watch(x) cout << #x << "=" << x << endl
#define watch2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define fitr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const ll mod = 1e9 + 7;
const int I = INT_MAX - 1;
const int Imn = INT_MIN + 1;
template <class A, class B>
ostream &operator<<(ostream &out, const pair<A, B> &a)
{
    return out << "(" << a.first << ", " << a.second << ")";
}
template <class A>
ostream &operator<<(ostream &out, const vector<A> &v)
{
    int i;
    out << "[";
    forn(i, sz(v))
    {
        if (i)
            out << ", ";
        out << v[i];
    }
    return out << "]";
}
ll Mod(ll x)
{
    if (x < 0)
        x += mod;
    x %= mod;
    return x;
}
ll Pow(ll x, ll n)
{
    if (n == 0)
        return 1;
    ll t = Pow(x, n / 2);
    t = Mod(t * t);
    if (n & 1)
        t = Mod(t * x);
    return Mod(t);
}

// ll ncr(int n, int r)
// {
//     ll p = 1, k = 1;
//     if (n - r < r)
//         r = n - r;
//     if (r != 0)
//         while (r)
//         {
//             // p = Mod(Mod(p) * Mod(n)), k = Mod(Mod(k) * Mod(r));
//             p *= n;
//             k *= r;
//             ll m = __gcd(p, k);
//             p /= m, k /= m;
//             n--, r--;
//         }
//     return Mod(p);
// }

ll ncr(ll n, ll r)
{
    ll i;
   
   double ans = 1;
    fork(i, n, r)
        ans *= ((double) i / double(i - r));
    return Mod(ans);
}

// ll nCr(ll n, ll r) // optimise function
// {
//     if (r == 0 || n == r)
//         return 1;
//     else
//         return Mod(nCr(n - 1, r - 1) + nCr(n - 1, r));
// }

ll t;
int main()
{
    ll a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, u, v, w, x, y, z;
    sl(t);
    while (t--)
    {
        sl(n);
        vl ar;
        sv(ar);
        ll mx = *max_element(all(ar));
        ll mxc = count(all(ar), mx);
        ll ans;
        if (mxc & 1)
            ans = Pow(2, n);
        else
            ans = Pow(2, n) - Mod((Pow(2, n - mxc) * ncr(mxc, mxc / 2)));
        cout << Mod(ans) << endl;
    }
    return 0;
}



