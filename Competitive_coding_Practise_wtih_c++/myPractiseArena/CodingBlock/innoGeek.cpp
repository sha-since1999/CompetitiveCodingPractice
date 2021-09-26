#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[] = {12, 41, 25, 6, 3, 56, 6, 3, 6, 7, 56, 8, 32};
    int n = sizeof(a) / sizeof(a[0]);
    int mn = INT16_MAX;
    int ans = 0;
    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        // mn = min(mn, a[i]);
        // ans = max(ans, a[i + 1] - mn);

        if (mn > a[i])
        {
            x = i;
            mn = a[i];
        }
        if (ans < (a[i + 1] - mn))
        {
            y = i + 1;
            ans = a[i + 1] - mn;
        }
    }

    cout << ans << "   " << x << "  " << y << endl;

    return 0;
}