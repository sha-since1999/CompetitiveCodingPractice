#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//problem : find no of zeros in factorial of given no.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    int ans = 0;
    while (n >= 5)
    {
        n /= 5;
        ans += n;
    }

    cout << ans << endl;

    return 0;
}