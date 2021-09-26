#include <bits/stdc++.h>
// #include "input.h"
using namespace std;
typedef long long ll;
int no_of_digit(ll x)
{
    int ans = 0;
    while (x > 0)
    {
        x /= 10;
        ans++;
    }
    return ans;
}
ll remove_digit(ll x, int j, int n)
{
    ll nx = 0;
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        int d = x % 10;
        x /= 10;
        if (i == j)

            continue;
        nx = d * pow(10, p++) + nx;
    }
    return nx;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll N, K;
        cin >> N;
        cin >> K;
        int nd = no_of_digit(N);
        ll ans = N % K;
        for (int i = 0; i < nd; i++)
        {
            ll D = remove_digit(N, i, nd);
            // cout << D << " ";
            ans = max(ans, D % K);
        }
        cout << ans << endl;
    }
    return 0;
}