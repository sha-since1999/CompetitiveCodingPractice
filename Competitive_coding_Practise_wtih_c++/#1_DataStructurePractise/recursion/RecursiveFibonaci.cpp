#include <bits/stdc++.h>
using namespace std;
int f[1000];
int fib(int n)
{
    if (n == 1 or n == 0)
        return n;
    if (f[n - 2] == -1)
        f[n - 2] = fib(n - 2);
    if (f[n - 1] == -1)
        f[n - 1] = fib(n - 1);
    return f[n - 2] + f[n - 1];
}
int simpleFib(int n)
{
    if (n <= 1)
        return n;
    return simpleFib(n - 2) + simpleFib(n - 1);
}
int main()
{
    int n = 5;
    cout << simpleFib(5) << endl;

    // fibonaci using memorization efficient
    memset(f, -1, sizeof(f));
    cout << fib(n) << endl;
    return 0;
}