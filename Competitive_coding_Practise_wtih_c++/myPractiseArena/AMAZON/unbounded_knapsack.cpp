#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int unboundedKnapsack(int W, int *wt, int *val, int n)
{
    if (n == 0 or W == 0)
        return 0;
    if (wt[n - 1] <= W)
        return max(val[n - 1] + unboundedKnapsack(W - wt[n - 1], wt, val, n), unboundedKnapsack(W, wt, val, n - 1));
    return unboundedKnapsack(W, wt, val, n - 1);
}

int unboundedKnapsackDP(int W, int *wt, int *val, int n)
{
    int dp[W + 1][n + 1] = {0};
    memset(dp, 0, sizeof(dp));
    for (int w = 1; w <= W; w++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (wt[i - 1] <= w)
                dp[w][i] = max(val[i - 1] + dp[w - wt[i - 1]][i], dp[w][i - 1]);
            else
                dp[w][i] = dp[w][i - 1];
        }
    }
    return dp[W][n];
}
int unboundedKnapsackDP1(int W, int *wt, int *val, int n)
{
    int dp[W + 1] = {0};
    memset(dp, 0, sizeof(dp));
    for (int w = 0; w <= W; w++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (wt[i - 1] <= w)
                dp[w] = max(dp[w], val[i - 1] + dp[w - wt[i - 1]]);
        }
    }
    return dp[W];
}

int main()
{
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val) / sizeof(val[0]);

    cout << unboundedKnapsack(W, wt, val, n) << endl;

    cout << unboundedKnapsackDP(W, wt, val, n);

    return 0;
}