#include <bits/stdc++.h>
using namespace std;

int gcd1(int a, int b) // basic method1
{
    int gcd;
    for (int i = 1; i <= a and i <= b; i++)
        if (a % i == 0 and b % i == 0)
            gcd = i;
    return gcd;
}
int gcd2(int a, int b) //basic method2
{
    if (a == 0 || b == 0)
        return 0;

    if (a == b)
        return a;

    if (a > b)
        return gcd2(a - b, b);
    return gcd2(a, b - a);
}

int GCD(int a, int b) // alternative recursive aproach
{
    if (!b)
        return a;
    return GCD(b, a % b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    cout << gcd1(a, b) << endl;
    cout << GCD(a, b) << endl;

    return 0;
}