#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int knapSack(int W, int *wt, int *val, int n)
{
    if (n == 0 or W == 0)
        return 0;
    if (wt[n - 1] <= W)
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
    return knapSack(W, wt, val, n - 1);
}

int knapSackMemorisation(int W, int *wt, int *val, int n)
{
    static int kp[1000][1000];
    memset(kp, -1, sizeof(kp));

    if (kp[W][n] != -1)
        return kp[W][n];

    if (n == 0 or W == 0)
        return kp[W][n] = 0;

    if (wt[n - 1] <= W)
        return kp[W][n] = max(val[n - 1] + knapSackMemorisation(W - wt[n - 1], wt, val, n - 1), knapSackMemorisation(W, wt, val, n - 1));

    return kp[W][n] = knapSackMemorisation(W, wt, val, n - 1);
}
int knapsackDP(int W, int *wt, int *val, int n)
{
    int dp[W + 1][n + 1] = {0};
    for (int w = 0; w <= W; w++)
    {
        for (int i = 0; i <= n; i++)
        {
            if (w == 0 or i == 0)
                dp[w][i] == 0;
            else if (wt[i - 1] <= w)
                dp[w][i] = max(val[i - 1] + dp[w - wt[i - 1]][i - 1], dp[w][i - 1]);
            else
                dp[w][i] = dp[w][i - 1];
        }
    }
    return dp[W][n];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n) << endl;
    cout << knapSackMemorisation(W, wt, val, n) << endl;
    cout << knapsackDP(W, wt, val, n);
    return 0;
}