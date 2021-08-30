#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll n, k;
        cin >> n >> k;
        int a[n];
        int h[100002];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            h[a[i]]++;
        }
        ll ans = 0,cnt=0;
        for (int x : h)
        {
            if (x > 1)
                ans++;
            if (x == 1)
                cnt += x;
        }
        ans += cnt / k;
        if (cnt % k != 0)
            ans++;
        ll ans1 = n / k;
        if (n % k != 0)
            ans1++;
        ans = min(ans, ans1);
        cout << ans << endl;
    }
    return 0;
}