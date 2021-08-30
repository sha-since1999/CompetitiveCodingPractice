#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    v[0] -= v[0];

    for (int i = 1; i < n; i++)
    {
        int x = (v[i] - (v[i] - 1));
        if (v[i] < x + v[i - 1])
        {
            cout << "No";
            return;
        }
        else
        {
            v[i] = (x + v[i - 1]);
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (v[i] <= v[i - 1])
        {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
    return;
}
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}