#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[100001], b[10001];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i] >> a[i];
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        b[i] += ans;
        int x = (b[i] % a[i]);
        if (x == 0)
            continue;
        ans += a[i] - x;
    }
    cout << ans << endl;
    return 0;
}

// problem statement:

// A company has N teams.The i’th team has a total budget of Ai units of money and it has Bi workers in it. Each team has to divide their budget within their workers equally. But for some teams, it’s not possible to divide the budget equally.
// Therefore, the company have to perform revisions in the teams’ budget sizes.

// In one revision, to revise the budget of i’th team, the budget of the first i teams has to be increased by 1.

// Your task is to find the minimum number of revisions needed so that for each team, equal distribution of their budget among the workers is possible.

// Input Format

// The first line contains an integer N, denoting the number of teams.
// Next N lines contain two space-separated integers, Ai and Bi, each.
// Constraints

// 1<=N<=105
// 0<=A<=109
// 1<=B<=109

// Output Format

// In a single line, print the minimum number of revisions needed so that for each team, equal distribution of their budget among the workers is possible.

// Sample TestCase 1

// Input

// 3
// 1 1
// 3 7
// 5 4

// Output

// 4

// Explanation

// Initially, the budget of the teams are 1, 3 and 5.

// In the first revision, the company will increase the budget for first 2 teams by 1.

// This will make the budgets as 2, 4 and 5.

// In next 3 revisions, the company will increase the budget of first 3 teams by 1.

// The final budgets will be 5, 7 and 8 which can now be equally distributed within each team.

// You cannot achieve the equal distribution characteristic in less than four revisions
