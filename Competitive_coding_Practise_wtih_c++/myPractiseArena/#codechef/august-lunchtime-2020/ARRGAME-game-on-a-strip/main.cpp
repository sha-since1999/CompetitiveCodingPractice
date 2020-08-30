#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
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
const int mod = 1e9 + 7;
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
int Mod(int x)
{
    x %= mod;
    if (x < 0)
        x += mod;
    return x;
}
int Pow(int x, int n)
{
    if (n == 0)
        return 1;
    int t = Pow(x, n / 2);
    t = Mod(t * t);
    if (n & 1)
        t = Mod(t * x);
    return t;
}
void sahu()
{
#ifndef MY_OFFLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !MY_OFFLINE_JUDGE
}
int t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // sahu();
    int a, b, cnt = 0, d, e = 0, f, g, h, i, j, k, l, m, n, o = 0, p, q, r, u, v, w, x, y, z;
    char ch;
    string s;
    si(t);
    while (t--)
    {
        o = 0, e = 0, cnt = 0;
        x = 0, y = 0;
        si(n);
        vi ar;
        sv(ar);
        unordered_map<int, int> mp;
        forn(i, n)
        {
            if (ar[i] == 0)
                cnt++;
            else if (cnt > 0)
            {
                mp[cnt]++;

                cnt = 0;
            }
        }
        if (cnt != 0)
            mp[cnt]++;

        x = 0;
        for (auto mm : mp)
        {
            if (x < mm.first)
                x = mm.first;
        }
        y = mp[x];
        // watch2(x, y);

        if ((x & 1) and y < 2)
            ps("Yes");
        else
            ps("No");
    }
    return 0;
}
