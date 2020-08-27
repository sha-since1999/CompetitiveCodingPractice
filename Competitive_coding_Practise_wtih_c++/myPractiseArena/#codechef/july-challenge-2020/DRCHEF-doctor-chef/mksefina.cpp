#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define intl long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        intl n;
        cin >> n;
        intl a[n + 1], b[n + 1];
        unordered_map<intl, intl> acnt, bcnt;
        map<intl, intl> mp;
        intl mn1 = INT_MAX, mn2 = INT_MAX;
        for (intl i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < mn1)
                mn1 = a[i];
            mp[a[i]]++;
            acnt[a[i]]++;
        }
        for (intl j = 0; j < n; j++)
        {
            cin >> b[j];
            if (mn2 > b[j])
            {
                mn2 = b[j];
            }
            mp[b[j]]++;
            bcnt[b[j]]++;
        }
        bool flag = false;
        for (auto i : mp)
        {
            if (i.second & 1)
            {
                flag = true;
                break;
            }
            if (acnt[i.first] == bcnt[i.first])
                mp[i.first] = 0;
            else if (acnt[i.first] > bcnt[i.first])
            {
                mp[i.first] = acnt[i.first] - (acnt[i.first] + bcnt[i.first]) / 2;
            }
            else
            {
                mp[i.first] = bcnt[i.first] - (acnt[i.first] + bcnt[i.first]) / 2;
            }
        }
        if (flag)
        {
            cout << "-1" << endl;
        }
        else
        {
            intl m = min(mn1, mn2);
            vector<intl> v;
            for (auto i : mp)
                v.push_back(i.first);
            intl i = 0, j = v.size() - 1;
            intl ans = 0;
            while (i <= j)
            {
                if (mp[v[i]] == 0)
                {
                    i++;
                    continue;
                }
                if (mp[v[j]] == 0)
                {
                    j--;
                    continue;
                }
                if (i > j)
                    break;
                mp[v[i]]--;
                mp[v[j]]--;
                ans += (min(min(v[i], v[j]), 2 * m));
            }
            cout << ans << endl;
        }
    }
}