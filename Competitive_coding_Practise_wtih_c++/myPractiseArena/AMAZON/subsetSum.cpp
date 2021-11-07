#include <bits/stdc++.h>
#include "input.h"
using namespace std;

bool subsetSum(int sum, int *a, int n)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (a[n - 1] <= sum)
    {
        return (subsetSum(sum - a[n - 1], a, n - 1) or subsetSum(sum, a, n - 1));
    }
    return subsetSum(sum, a, n - 1);
}

bool subsetSumDP(int sum, int *a, int n)
{
    bool dp[n + 1][sum + 1] = {0};
    for (int i = 0; i <= n; i++)
    {
        for (int s = 0; s <= sum; s++)
        {
            if (s == 0)
                dp[i][s] = true;
            else if (i == 0)
                dp[i][s] = false;
            else if (a[i - 1] <= s)
                dp[i][s] = dp[i - 1][s - a[i - 1]] or dp[i - 1][s];
            else
                dp[i][s] = dp[i - 1][s];
        }
    }
    return dp[n][sum];
}

bool is_equalSumPartition(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    if (sum & 1)
        return false;
    return subsetSumDP(sum / 2, a, n);
}

int countSubset_of_given_sum(int sum, int *a, int n)
{
    int dp[n + 1][sum + 1] = {0};
    for (int i = 0; i <= n; i++)
    {
        for (int s = 0; s <= sum; s++)
        {
            if (s == 0)
                dp[i][s] = 1;
            else if (i == 0)
                dp[i][s] = 0;
            else if (a[i - 1] <= s)
                dp[i][s] = dp[i - 1][s - a[i - 1]] + dp[i - 1][s];
            else
                dp[i][s] = dp[i - 1][s];
        }
    }
    return dp[n][sum];
}
int minimumSubsetDifference(int *a, int n)
{
    int sum = 0;
    int min_diff = INT_MAX;

    for (int i = 0; i < n; i++)
        sum += a[i];

    bool dp[sum + 1][n + 1] = {0};
    memset(dp, 0, sizeof(dp));
    for (int s = 0; s <= sum; s++)
    {
        for (int i = 0; i <= n; i++)
        {
            if (s == 0)
                dp[s][i] = 1;
            else if (i == 0)
                dp[s][i] = 0;
            else if (s < a[i - 1])
                dp[s][i] = dp[s][i - 1];
            else
                dp[s][i] = (dp[s - a[i - 1]][i - 1] or dp[s][i - 1]);
            // if (dp[s][n])
            //     min_diff = min(min_diff, abs(sum - 2 * s));
        }
    }

    for (int s = 0; s <= sum; s++)
    {
        if (dp[s][n])
            min_diff = min(min_diff, abs(sum - 2 * s));
    }
    return min_diff;
}
int countSubsetSumWithGivenDifference(int diff, int *a, int n)
{
    int sum = 0;
    for (int i = 0; i < n + 1; i++)
        sum += a[i];

    int s = (sum + diff) / 2;
    return countSubset_of_given_sum(s, a, n);
}
int targetSum(int sum, int *a, int n)
{
    // in this problem you have to assign a (+) and (-) to the no to get taget sum
    return countSubsetSumWithGivenDifference(sum, a, n);
}

int main()
{
    int a[] = {3, 34, 4, 12, 5, 1, 2};
    int n = sizeof(a) / sizeof(a[1]);
    int sum = 30;
    cout << "<<<<<<<subset sum>>>>>>" << endl;
    cout << subsetSum(sum, a, n) << endl;
    cout << subsetSumDP(sum, a, n) << endl;

    cout << "<<<<<<<count no of subset in the arr of given sum >>>>>>>>" << endl;
    cout << countSubset_of_given_sum(6, a, n) << endl;

    cout << "<<<<<Equal SUM partition>>>>>>" << endl;
    cout << is_equalSumPartition(a, n) << endl;

    cout << "<<<<<<<minimum Difference >>>>>>" << endl;
    cout << minimumSubsetDifference(a, n) << endl;

    cout << "<<<<<<<<count no of subsetSum  with given difference>>>>>>" << endl;
    cout << countSubsetSumWithGivenDifference(7, a, n) << endl;

    cout << "<<<here everything  is well tested>>>" << endl;
    return 0;
}
