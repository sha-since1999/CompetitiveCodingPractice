#include <bits/stdc++.h>
//#include "sahu.h"
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int a[3], d, e;
        cin >> a[0] >> a[1] >> a[2] >> d >> e;
        int mnd = INT_MAX;
        int x = INT_MAX, sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += a[i];
            if (e >= a[i] and mnd > e - a[i])
            {
                mnd= e - a[i];
                x = a[i];
            }
        }
        if (x <= e and (sum - x) <= d)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
