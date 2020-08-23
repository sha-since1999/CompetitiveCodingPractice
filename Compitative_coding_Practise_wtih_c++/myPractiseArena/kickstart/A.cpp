#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define forn(i, n) for (i = 0; i < n; i++)
#define fork(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long int
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
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

int main()
{
    // sahu();
    int i, j, x, y, z, k, l, n, m, o, p, q, r, s, t, u, v;
    si(t);
    int case_no = 1;
    while (t--)
    {
        vi v;
        cin >> n;
        forn(i, n) si(p), v.pb(p);
        int ans = 2;
        int d = 0;
        s = 2;
        o = v[1] - v[0];
        fork(i, 2, n)
        {
            d = v[i] - v[i - 1];
            if (d == o)
                s++, ans = max(s, ans);
            else
                o = d, s = 2;
        }

        cout << "Case #" << case_no++ << ": " << ans << endl;
    }

    return 0;
}
//testcase
// 4
// 7
// 10 7 4 6 8 10 11
// 4
// 9 7 5 3
// 9
// 5 5 4 5 5 5 4 5 6
// 10
// 5 4 3 2 1 2 3 4 5 6