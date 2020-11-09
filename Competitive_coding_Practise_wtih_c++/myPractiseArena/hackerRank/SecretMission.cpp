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
clock_t tStart;
void sahu()
{
    tStart = clock();
#ifndef MY_OFFLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !MY_OFFLINE_JUDGE
}
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void tle()
{
#ifndef MY_OFFLINE_JUDGE
    fprintf(stderr, "Runtime: %.10f s", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif // !MY_OFFLINE_JUDGE
}
int main()
{
    // fastio();
    // sahu();
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, u, w, x, y, z;
    si(n);
    vi mxrs;
    vpii v;
    int t = n;
    forn(i, n)
    {
        cin >> x >> y;
        v.eb(x, y);
    }
    i = 0;
    forn(i, n)
    {
        auto pt1 = v[i];
        int x1 = pt1.F;
        int y1 = pt1.S;
        // watch2(x1, y1);
        fork(j, i + 1, n)
        {
            auto pt2 = v[j];
            int x2 = pt2.F;
            int y2 = pt2.S;
            // watch2(x1, y1);
            // watch2(x2, y2);
            int m = (y2 - y1) / (x2 - x1);
            int mxcnt = 2;
            fork(k, j + 1, n)
            {
                auto pt3 = v[k];
                x = pt3.F;
                y = pt3.S;
                int rhs = (m * (x - x1)) + y1;
                if (y == rhs)
                {
                    mxcnt++;
                }
            }
            // cout << mxcnt;
            mxrs.pb(mxcnt);
        }
    }
    int ans = *max_element(all(mxrs));
    cout << ans << endl;

    //tle();
    return 0;
}