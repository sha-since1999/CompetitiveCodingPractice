#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int no_of_ways(int n, int s, int k)
{
    if (n < s)
        return 0;
    if (n == s)
        return 1;
    int sum = 0;
    for (int i = 1; i <= k; i++)
    {
        sum += no_of_ways(n - i, s, k);
    }
    return sum;
}
int no_of_waysDP(int n, int s, int k)
{
    int dp[n + 1] = {0};
    dp[s] = 1;
    for (int i = s; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i] += dp[i - j];
        }
    }
    return dp[n];
}

int main()
{
    int n = 6;
    cout << no_of_ways(n, 2, 3) << endl;
    cout << no_of_waysDP(n, 2, 3) << endl;
    return 0;
}
// 123456
// 1111
// 22
// 112
// 121
// 211
// 13
// 31
