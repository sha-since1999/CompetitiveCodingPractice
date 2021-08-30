#include <bits/stdc++.h>

using namespace std;
int fastPow(int a, int b)
{
    int res = 1;
    if (b == 0)
        return res;
    while (b > 0)
    {
        if (b & 1)
            res *= a, b--;
        else
            res *= res, b /= 2;
    }
    return res;
}
int pow(int a, int n)
{
    if (n == 0)
        return 1;
    return a * (a, n - 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    cout << fastPow(x, y) << endl;

    return 0;
}