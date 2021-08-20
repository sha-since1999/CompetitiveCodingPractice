#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int p = 1;
    int ans = 0;
    while (n > 0)
    {

        int d = n % 10;
        ans += p * d;
        p <<= 1;
        n /= 10;
    }
    cout << ans << endl;
    return 0;
}