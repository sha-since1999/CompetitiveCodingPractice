#include <bits/stdc++.h>
using namespace std;
static int t[100][100];
int rsolve(int *A, int i, int j)
{
    if (i >= j)
        return 0;
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = rsolve(A, i, k) + rsolve(A, k + 1, j) + (A[i - 1] * A[k] * A[j]);
        if (mn > temp)
            mn = temp;
    }
    return mn;
}
int rmOptimiseSolve(int *A, int i, int j)
{
    if (i >= j)
        return 0;
    int mn = INT_MAX;
    if (t[i][j] != -1)
        return t[i][j];
    int left, right;
    for (int k = i; k < j; k++)
    {
        if (t[i][k] != -1)
            left = t[i][k];
        else
            left = t[i][k] = rmOptimiseSolve(A, i, k);

        if (t[k + 1][j] != -1)
            right = t[k + 1][j];
        else
            right = t[k + 1][j] = rmOptimiseSolve(A, k + 1, j);

        int temp = left + right + (A[i - 1] * A[k] * A[j]);
        if (mn > temp)
            mn = temp;
    }
    return t[i][j] = mn;
}
// int MCM(int *A, int n)
// {
//     int dp[n + 1][n + 1];

//     for (int i = 1; i < n + 1; i++)
//         for (int j = 1; j < n + 1; j++)
//         {

//             dp[i][j] = 0;
//         }

//     for (int i = 1; i < n + 1; i++)
//     {
//         for (int j = 1; j < n + 1; j++)
//         {
//             dp[i][j] = INT_MAX;

//             for (int k = i; k < j; k++)
//             {
//                 int temp = dp[i][k] + dp[k + 1][j] + (A[i - 1] * A[k] + A[j]);
//                 if (temp <= dp[i][j])
//                     dp[i][j] = temp;
//             }
//         }
//     }
//     return dp[n][n];
// }
static unordered_map<string, int> mp;
int isScramble(string x, string y)
{
    if (x.compare(y) == 0)
        return true;
    if (x.size() <= 1)
        return false; //bec in scramble string empty string in any side of bst is not allowed
    string s = x;
    s.push_back('_');
    s.append(y);
    if (mp.find(s) != mp.end())
    {
        return mp[s];
    }
    int n = x.size();
    bool flag = 0;
    for (int k = 1; k < n; k++)
    {
        if ((isScramble(x.substr(0, k), y.substr(n - k, k)) == true) && (isScramble(x.substr(k, n - k), y.substr(0, n - k)) == true)) //when swapping true case
        {
            flag = true;
            break;
        }
        if ((isScramble(x.substr(0, k), y.substr(0, k)) == true) && (isScramble(x.substr(k, n - k), y.substr(k, n - k))) == true) //when swapping false case
        {
            flag = true;
            break;
        }
    }
    return mp[s] = flag;
}
bool isPalindrome(string s, int i, int j)
{
    if (i >= j)
        return true; // this specially for this to check if string is empty then it is palindrome itself
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}
int minimumPalindromicPartition(string s, int i, int j)
{
    if (i >= j)
        return false;
    if (isPalindrome(s, i, j))
        return 0;
    int mn = INT_MAX;
    for (int k = i; i < j; k++)
    {
        int temp = 1 + minimumPalindromicPartition(s, i, k) + minimumPalindromicPartition(s, k + 1, j);
        if (temp < mn)
            mn = temp;
    }
    return mn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(t, -1, sizeof(t));
    int A[4] = {10, 30, 5, 60};
    // cout << rsolve(A, 1, 3) << endl;
    // cout << rmOptimiseSolve(A, 1, 3) << endl;
    // cout << "ans:  " << isScramble("abc", "cba") << endl;
    cout << "ans:  " << minimumPalindromicPartition("nitind", 0, 5) << endl;
    return 0;
} // in this only minimum palindromicpartition cause a problem only and everythig fine except it