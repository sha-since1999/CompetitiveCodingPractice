#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int mx, np;
    cin >> mx >> np;
    int ans = 0;
    //  case 1
    int x = 1;
    int n = x << (np - 1);
    while (true)
    {

        if (n <= mx)
            ans += (mx - n) + 1;
        else
            break;
        n >>= 1;
        n++;
        n = n << 1;
    }
    cout << ans << endl;
    return 0;
}

