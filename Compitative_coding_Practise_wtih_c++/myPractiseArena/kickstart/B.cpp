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
const int inf = INT_MAX - 1;
const int mninf = INT_MIN + 1;

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
    ;
}

void sahu()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef MY_OFFLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !MY_OFFLINE_JUDGE
}
int main()
{
    // sahu();
    int a, b, c, d, e, f, g, e, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, x, y, z;
    si(t);
    int case_no = 1;
    while (t--)
    {
        cin >> n >> a >> b >> c;
        vi vec(n, 1);
        bool flag = 1;
        if (a == n and c == n and c != n)
            flag = 0;
        if (a + b - c >= n)
            flag = 0;
        if (flag)
        {
            int i = 0;

            j = 0;
            y = a - c;
            int sb = n - y - 1 - (c - 1) - (a - 2);
            forn(i, y) vec[j++] += sb++;

            o = 0;
            x = b - c;
            sb = n - x - 1 - (c - 1);
            forn(i, x) vec[n - 1 - o] += sb++, o++;
            i = 0;
            m = a - 1;

            if (a == c)
                while (c--)
                    vec[i++] = n;
            else if (b == c)
                while (c--)
                    vec[n - 1 - i++] = n;
            else
                while (c--)
                    vec[m++] = n;

            cout << "Case #" << case_no++ << ": ";
            for (int i : vec)
                cout << i << " ";
            cout << endl;
        }
        else
        {
            cout << "Case #" << case_no++ << ": IMPOSSIBLE" << endl;
        }
    }

    return 0;
}

//test case
// 3
// 4 1 3 1
// 4 4 4 3
// 5 3 3 2