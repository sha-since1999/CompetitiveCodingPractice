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
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int mod = 1e9 + 7;
const int I = INT_MAX - 1;
const int Imn = INT_MIN + 1;
template <class A, class B>
void sahu(){

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
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, u, v, w, x, y, z;
    char ch;
    string s;
    si(t);
    while (t--)
    {
        si(n);
        int ar[65][65];
        forn(i, n) forn(j, n) si(ar[i][j]);
        i = 0;
        a = 0;
        bool flag = 1;
        fork(j, n - 1, -1)
        {
            if (ar[i][j] != ar[j][i])
            {
                if (ar[i][j] > ar[j][i] and flag)
                    a++, flag = 0;
                else if (ar[i][j] < ar[j][i] and !flag)
                    a++, flag = 1;
            }
        }
        cout << a << endl;
    }
    return 0;
}
