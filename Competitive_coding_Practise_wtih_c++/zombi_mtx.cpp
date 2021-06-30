#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isvalid(int mid, int a[], int m, int n)
{

    int zm = 1, sum = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] > mid)
            return false;

        if (sum + a[i] <= mid)
        {
            sum += a[i];
            continue;
        }

        else if (sum + a[i] > mid)
        {
            zm++;
            sum = a[i];
        }
    }

    if (zm > m)
        return false;

    return true;
}

signed main()
{

    int n, m;
    cin >> n;

    int a[n];
    int total = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        total += a[i];
    }
    cin >> m;
    int start = 1, end = total, mid;
    int ans = INT_MAX;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (isvalid(mid, a, m, n))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
