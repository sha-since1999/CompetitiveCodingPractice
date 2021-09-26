#include <bits/stdc++.h>
//#include "sahu.h"
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll N;
        cin >> N;
        int odd = 0, even = 0;
        int a[N];
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
            if (a[i] & 1)
                odd++;
            else
                even++;
        }
        int ans = 0;
        if (N & 1)
        {
            if (even >N / 2 + 1)
                ans +=N / 2 + 1;
            else
                ans += even;
            if (odd >N / 2)
                ans +=N / 2;
            else
                ans += odd;
        }
        else
        {
            if (even >N / 2)
                ans +=N / 2;
            else
                ans += even;
            if (odd >N / 2)
                ans +=N / 2;
            else
                ans += odd;
        }
        cout << ans << endl;
    }
    return 0;
}