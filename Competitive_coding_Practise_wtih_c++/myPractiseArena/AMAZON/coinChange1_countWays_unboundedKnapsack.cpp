#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int count(int sum, int *a, int n)
{
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    if (n <= 0 and sum >= 1)
        return 0;

    if (a[n - 1] <= sum)
        return count(sum - a[n - 1], a, n) + count(sum, a, n - 1);
    return count(sum, a, n - 1);
}

int countDP(int sum, int *a, int n)
{
    int dp[sum + 1][n + 1] = {0};
    for (int s = 0; s <= sum; s++)
    {
        for (int i = 0; i <= n; i++)
        {
            if (s == 0)
                dp[s][i] = 1;
            else if (s < 0)
                dp[s][i] = 0;
            else if (i <= 0 and s >= 1)
                dp[s][i] = 0;
            else if (a[i - 1] <= s)
                dp[s][i] = dp[s - a[i - 1]][i] + dp[s][i - 1];
            else
                dp[s][i] = dp[s][i - 1];
        }
    }
    return dp[sum][n];
}
int countDP1(int sum, int *a, int n) // space complexity O(n)
{
    int dp[sum + 1] = {0};
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int s = a[i]; s <= sum; s++)
            dp[s] += dp[s - a[i]];
    }
    return dp[sum];
}
int main()
{
    int i, j;
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << " " << count(4, arr, n) << endl;
    cout << " " << countDP(4, arr, n) << endl;
    cout << " " << countDP1(4, arr, n) << endl;

    return 0;
}

// 112
// 22
// 31
// 1111