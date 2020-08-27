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

bool diophantineSoln(int a, int b, int c, int &x, int &y, int &g)
{
    g = extendedGcd(a, b, x, y);
    if (c % g)
        return false;
    x = x * (c / g);
    y = y * (c / g);
    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, x, y, c, g;
    cin >> a >> b >> c;
    bool ans = diophantineSoln(a, b, c, x, y, g);
    if (ans)
    {
        cout << "GCD::  " << g << endl;
        cout << "x :  " << x << endl;
        cout << "y :  " << y << endl;
    }
    else
    {
        cout << "there is no solution" << endl;
    }

    return 0;
}