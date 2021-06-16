#include <bits/stdc++.h>
using namespace std;
#define intl long long int
#define ll long long
#define pb push_back
#define ipair pair<intl, intl>
#define mp make_pair
#define fo(i, s, e) for (intl i = s; i <= e; i++)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl "\n"
#define mod 1000000007
int nToKGroups(int n, int k)
{
    if (n < k)
    {
        return 0;
    }
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= k; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - i];
            }
        }
    }
    return dp[k][n];
}
int main()
{
    intl n, k;
    cin >> n >> k;
    cout << nToKGroups(n, k);
    return 0;
}
