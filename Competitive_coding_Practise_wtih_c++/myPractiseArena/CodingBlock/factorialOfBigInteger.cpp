#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int multiply(int *, int, int);
int factorial(int *res, int n)
{
    res[0] = 1;
    int res_size = 1;
    for (int i = 2; i <= n; i++)
    {

        res_size = multiply(res, res_size, i);
    }

    return res_size;
}
int multiply(int *res, int res_size, int x)
{
    int i;
    int carry = 0;
    for (i = 0; i < res_size; i++)
    {
        int tmp = (res[i] * x) + carry;
        res[i] = tmp % 10;
        carry = tmp / 10;
    }
    while (carry > 0)
    {
        res[i++] = carry % 10;
        carry /= 10;
        res_size++;
    }
    return res_size;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int res[1000];
    int res_size = factorial(res, 100);
    for (int i = res_size - 1; i >= 0; i--)
        cout << res[i];
    return 0;
}