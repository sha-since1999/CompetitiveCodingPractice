#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull nth_catalon(int n)
{
    ull dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - j - 1];
    }
    return dp[n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 10; i++)
        cout << nth_catalon(i) << " ";

    return 0;
}
