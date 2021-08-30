#include <bits/stdc++.h>
using namespace std;
#include "input.h"

int main()
{

    int dis_out;
    cin >> dis_out;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mn = INT32_MAX;
    int ans = INT32_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = abs(a[j] - a[i]);
            int close_value = (abs(diff - dis_out));
            if (mn > close_value)
            {
                mn = close_value;
                ans = a[i] + a[j];
            }
            if (mn == close_value)
                ans = min(ans, a[i] + a[j]);
        }
    }

    cout << ans << endl;
    return 0;
}
