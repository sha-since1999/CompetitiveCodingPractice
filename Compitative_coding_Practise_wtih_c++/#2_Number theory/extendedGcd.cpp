#include <bits/stdc++.h>
using namespace std;
int extendedGcd(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0,
        y = 1;
        return b;
    }
    int x1, y1;
    int ans = extendedGcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, x, y, ans;
    cin >> a >> b;
    ans = extendedGcd(a, b, x, y);
    cout << "ans::  " << ans << endl;
    cout << "x :  " << x << endl;
    cout << "y :  " << y << endl;

    return 0;
}