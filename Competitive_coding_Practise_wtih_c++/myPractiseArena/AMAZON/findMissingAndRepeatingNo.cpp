#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        xr ^= a[i];
        xr ^= (i + 1);
    }
    // now xor contains both missing and duplicate no;
    int p = 0;

    while (!(xr & 1))
    {
        p++;
        xr >>= 1;
    }

    int axor = 0;
    int bxor = 0;
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int y = i + 1;
        if ((x >> p) & 1)
            axor ^= x;
        else
            bxor ^= x;
        if ((y >> p) & 1)
            axor ^= y;
        else
            bxor ^= y;
    }
    cout << "missing no:" << axor << "  duplicate no: " << bxor << endl;
    return 0;
}

// 6
// 4 3 1 5 2 4
// o / p = missing no : 6 duplicate no : 4