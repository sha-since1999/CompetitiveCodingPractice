#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int LCS(string a, string b, int n, int m)
{
    if (n == 0 or m == 0)
        return 0;
    if (a[n - 1] == b[m - 1])
        return 1 + LCS(a, b, n - 1, m - 1);
    return max(LCS(a, b, n - 1, m), LCS(a, b, n, m - 1));
}

int LCSdp(string a, string b, int n, int m)
{
    int dp[n + 1][m + 1] = {0};
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

string printLCS(string a, string b, int n, int m)
{
    int dp[n + 1][m + 1] = {0};
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string s = "";
    int i = n, j = m;
    while (i > 0 and j > 0)
    {
        if (a[i - 1] == b[j - 1])

        {
            s.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    string a = "rohitssahu";
    int n = a.size();
    string b = "sahusRohit";
    int m = b.size();

    cout << "Length of longest common subsequences" << LCS(a, b, n, m) << endl;
    cout << "Length of longest common subsequences" << LCSdp(a, b, n, m) << endl;
    cout << " longest common subsequences      : " << printLCS(a, b, n, m) << endl;
    return 0;
}