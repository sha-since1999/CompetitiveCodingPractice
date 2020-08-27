#include <bits/stdc++.h>
using namespace std;
class KnapsackProblem
{
public:
    bool subset_sum(int *, int, int);
    bool is_equalSumPartition(int *, int, int);
    int count_subset(int *, int, int);
    int noOfSubsetSumWithGivenDifference(int *, int, int);
    int minimumSubsetSum(int *, int, int);
    int targetSum(int *, int, int);

    //KnapsackUnbound problem start from here

    int coinChange1(int *, int, int);
    int coinChange2(int *, int, int);
    int rodCutting_probelem(int *, int);
};
bool KnapsackProblem::subset_sum(int *A, int sum, int n)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
            if (A[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - A[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];

    return dp[n][sum];
}
bool KnapsackProblem::is_equalSumPartition(int *A, int sum, int n)
{
    for (int i = 0; i < n; i++)
        sum += A[i];
    if (sum % 2 == 1)
        return -1;
    if (sum % 2 == 0)
        sum /= 2;
    return subset_sum(A, sum, n);
}
int KnapsackProblem::count_subset(int *A, int sum, int n)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (A[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - A[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }

    // for (int i = 0; i < n + 1; i++)
    //    { for (int j = 0; j < sum + 1; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    //    }//to check matrix only
    return dp[n][sum];
}
int KnapsackProblem::noOfSubsetSumWithGivenDifference(int *A, int diff, int n)
{
    int sum = 0;
    for (int i = 0; i < n + 1; i++)
        sum += A[i];

    sum = (sum + diff) / 2;
    return count_subset(A, sum, n);
}
int KnapsackProblem::targetSum(int *A, int sum, int n)
{
    //in this there is problem you have to asssign plus or minus  to the no. such that target sum can be achieved;
    // similar problem as the subset sum with given difference

    return noOfSubsetSumWithGivenDifference(A, sum, n);
}
int KnapsackProblem::coinChange1(int *coin, int sum, int n)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
            if (coin[i - 1] <= j)
                dp[i][j] = dp[i][j - coin[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];

    return dp[n][sum];
}
int KnapsackProblem::coinChange2(int *coin, int sum, int n) //in this proble
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                dp[i][j] = 0;
            if (i == 0)
                dp[i][j] = INT_MAX - 1;

            if (i == 1 && j % coin[0] == 0)
                dp[i][j] = j / coin[0];
            else if (i == 1 && j % coin[0] != 0)
                dp[i][j] = INT_MAX - 1;
        }
    }
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)

                dp[i][j] = min(1 + dp[i][j - coin[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int KnapsackProblem::rodCutting_probelem(int *A, int n)
{
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 6;
    int sum = 11;
    int A[] = {3, 2, 4, 8, 7, 9};
    int coin[] = {1, 2, 3, 5};
    KnapsackProblem kp;
    // cout << kp.subset_sum(A, sum, n) << endl;for
    // cout << kp.is_equalSumPartition(A, sum, n) << endl;
    // cout << kp.count_subset(A, sum, n) << endl;
    // cout << kp.coinChange1(coin, 5, 3) << endl;
    cout << kp.coinChange2(coin, 5, 3) << endl;
    // cout << kp.noOfSubsetSumWithGivenDifference(A, 2, n) << endl;

    return 0;
} // int this problem every thing is tested  properly ;
  // only only one known problem remain to implement which you have to see from  gfg;