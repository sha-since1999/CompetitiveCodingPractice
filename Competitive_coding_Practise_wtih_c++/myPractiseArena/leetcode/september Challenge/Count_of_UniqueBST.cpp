#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTrees(int x) // dp  solution of finding catalon numbers
    {
        int dp[20] = {0};
        dp[0] = dp[1] = 1;
        for (int n = 2; n <= x; n++)
            for (int i = 0; i < n; i++)
                dp[n] += dp[i] * dp[n - 1 - i];
        return dp[x];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sl;
    cout << sl.numTrees(4) << endl;

    return 0;
}

// note : in this problem you have to count no of possible BST  with the Given nodes
// we can apply catalon formula  to find
// that's why i  use catalon  using with dp (optimize Solution);