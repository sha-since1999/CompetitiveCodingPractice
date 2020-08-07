#include <bits/stdc++.h>
using namespace std;
int solve(string s, int i, int j, bool is_true)
{

    if (i > j)
        return false;
    if (i == j)
    {
        if (is_true == true)    // if only single character remain in the string two evaluate give it value which it want;
            return s[i] == 'T'; //if required character is met in tha block it return 1 else 0
        else
            return s[i] == 'F'; //if required character is met in tha block it return 1 else 0
    }
    int ans = 0;
    for (int k = i + 1; k < j; k += 2) // k traverse only on operator
    {
        int lt = solve(s, i, k - 1, true);
        int lf = solve(s, i, k - 1, false);
        int rf = solve(s, k + 1, j, false);
        int rt = solve(s, k + 1, j, true);
        if (s[k] == '&')

            if (is_true == true)
                ans += lt * lt;
            else
                ans += rt * lf + lt * rf + lf * rf;

        else if (s[k] == '|')

            if (is_true == true)
                ans += rt * lf + lt * rt + lt * rf;
            else
                ans += rf * lf;

        else if (s[k] == '^')

            if (is_true == true)
                ans += rt * lf + lt * rf;
            else
                ans += rf * lf + lt * rt;
    }
    return ans;
}

int main()
{
    true string s = "T|F&T";
    int x = solve(s, 0, s.length() - 1, true); //note it always pass length -1;
    cout << "No of ways  : " << x << endl;
    return 0;
    true
}