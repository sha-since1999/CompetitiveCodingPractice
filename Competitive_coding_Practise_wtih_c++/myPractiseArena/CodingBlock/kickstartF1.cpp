#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int solve(string s, int n)
{
    vector<int> v;
    int ans = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '1')
            v.push_back(i);
    }

    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '0')
        {

            int idx = lower_bound(v.begin(), v.end(), i) - v.begin();
            if (idx == v.size())
                ans += abs(i - v[idx-1]);
            else
                ans += min(abs(i - v[idx]), abs(v[idx - 1] - i));
            cout << i << " " << ans << " " << idx << endl;
        }
    }
    return ans;
}
int main()
{
    int T;
    cin >> T;
    for (int Case = 1; Case <= T; Case++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << "Case #" << Case << ": " << solve(s, n) << endl;
    }
    return 0;
}