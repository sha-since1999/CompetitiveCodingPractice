#include <bits/stdc++.h>
using namespace std;
static int dp[50][50]; //only for recursive memoize and for createing a table for printing purpose this matrix is use function if needed

int longestCommonSubsequence(string x, string y, int m, int n)
{

    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[m][n];
}
int longestCommonSubstring(string x, string y, int m, int n)
{
    int ans = 0;
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
        }
    }
    return dp[m][n];
}
int rmlcs(string x, string y, int m, int n)
{
    int ans = 0;
    if (m == 0 || n == 0)
        return false;
    if (dp[m][n] != -1)
        return dp[m][n];
    if (x[n - 1] == y[m - 1])
        ans = 1 + rmlcs(x, y, m - 1, n - 1);
    else
        ans = max(rmlcs(x, y, m - 1, n), rmlcs(x, y, m, n - 1));
    return dp[m][n] = ans;
}
int ShortestCommonSuperSequence(string x, string y, int m, int n)
{
    return m + n - longestCommonSubsequence(x, y, m, n);
}
int minimumNoOfInsertionDeletionRequire(string x, string y, int m, int n)
{
    int l = longestCommonSubsequence(x, y, m, n);
    cout << "deletion: " << m - l << endl;
    cout << "Inertion: " << n - l << endl;
    return 0;
}
string printlongestCommonSubsequence(string x, string y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    string s = "";
    int i = m;
    int j = n;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s += x[i - 1];
            i--;
            j--;
        }
        if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(s.begin(), s.end());
    return s;
}

string printSmallestSuperSequence(string x, string y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    string s = "";
    int i = m;
    int j = n;

    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s.push_back(x[i - 1]);
            i--;
            j--;
        }
        if (dp[i - 1][j] > dp[i][j - 1])
        {
            s.push_back(x[i - 1]);
            i--;
        }
        else
        {
            s.push_back(y[j - 1]);
            j--;
        }
    }
    while (i > 0)
    {
        s.push_back(x[i - 1]);
        i--;
    }
    while (j > 0)
    {
        s.push_back(y[j - 1]);
        j--;
    }

    reverse(s.begin(), s.end());
    return s;
}
int longestRepeatingSubsequence(string x, int n)
{
    int dp[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == x[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    return dp[n][n];
}
bool sequencePatternMatching(string x, string y)
{
    if (longestCommonSubsequence(x, y, x.size(), y.size()) == x.size())
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    string x = "sahurohitsahu";
    string y = "rohslahu";
    int m = x.size();
    int n = y.size();
    // cout << rmlcs(x, y, m, m) << endl;
    // y = x;
    // reverse(x.begin(), x.end());

    // to find longest palindrome subsequence in the string pass string and reverse string to the function only you get desired thing

    // cout << ShortestCommonSuperSequence(x, y, m, n) << endl;
    // minimumNoOfInsertionDeletionRequire(x, y, m, n);
    // cout << sequencePatternMatching("sahu", x) << endl;

    cout << printlongestCommonSubsequence(x, y, m, n) << endl;
    // cout << printSmallestSuperSequence(x, y, m, n) << endl;
    // cout << longestRepeatingSubsequence(x, n) << endl;
    return 0;
}
// there is some problem in printing onlyl on scs and   lcs function
