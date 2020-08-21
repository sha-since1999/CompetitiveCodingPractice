#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
void catalon(int n)
{
    ull dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n;i++)
        for (int j = i; j <= n;j++)
            dp[i] = dp[j] + dp[i-j-1];

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*let's start sahu...*/

    return 0;
}