#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int cutRod(int sum, int *val, int n)
{
    if (n == 0 or sum == 0)
        return 0;
    if (n == 1)
        return val[n - 1];
    if (n <= sum)
        return max(val[n - 1] + cutRod(sum - n, val, n), cutRod(sum, val, n - 1));
    return cutRod(sum, val, n - 1);
}
int cutRodDP(int sum, int *val, int n)
{
    int dp[sum + 1][n + 1] = {0};
    for (int s = 0; s <= sum; s++)
    {
        for (int i = 0; i <= n; i++)
        {
            if (s == 0 or n == 0)
                dp[s][i] = 0;
            else if (i == 1)
                dp[s][i] = val[i - 1];
            else if (i <= s)
                dp[s][i] = max(val[i - 1] + dp[s - i][i], dp[s][i - 1]);
            else
                dp[s][i] = dp[s][i - 1];
        }
    }
    return dp[sum][n];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Obtainable Value is " << cutRod(8, arr, size) << endl;
    cout << "Maximum Obtainable Value is " << cutRodDP(8, arr, size) << endl;
    return 0;
}