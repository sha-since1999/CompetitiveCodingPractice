    #include <bits/stdc++.h>
    using namespace std;
    #define gc getchar_unlocked()

    #define endl "\n"
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

    ll findxor()
    {

        ll n;
        cin >> n;
        vector<ll> v;
        for (ll i = 1; i <= 20; i++)
        {
            cout << 1 << " " << (1ul << i) << endl;
            cout.flush();
            ll temp;
            cin >> temp;
            v.pb(temp);
        }
        reverse(v.begin(), v.end());
        ll vsum = v[0] - (n * (1ul << 20));
        for (ll i = 1; i < v.size(); i++)
        {
            if (v[i] >= vsum)
            {
                ll temp = ((1ul << v.size() - i));
                v[i] = (n - (v[i] - vsum) / temp) / 2;
            }
            else
            {
                ll temp = ((1ul << (v.size() - i)));
                v[i] = (n + (vsum - v[i]) / temp) / 2;
            }
        }
        ll ans = 0;
        for (ll i = 1; i < v.size(); i++)
        {
            if (v[i] & 1)
            {
                ll temp = ((1ul << (v.size() - i)));
                ans += temp;
            }
        }
        if (vsum & 1)
        {
            ans++;
        }
        cout << 2 << " " << ans << endl;
        cout.flush();
        ll lastans;
        cin >> lastans;
        return lastans;
    }
    int main()
    {
        fastio();
        ll t;
        cin >> t;
        while (t--)
        {
            if (!findxor())
                break;
            cout << endl;
            cout.flush();
        }
    }