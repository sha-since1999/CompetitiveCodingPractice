// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
const int mod = 1e9 + 7;
using namespace std;
typedef long long int ll;
vector<vector<ll>> powerset;
vector<ll> a;

void powerSet()
{
    int x = 1 << a.size();
    powerset.clear();
    for (int i = 0; i < x; i++)
    {
        int temp = i;
        int idx = 0;
        vector<ll> currSubset;
        while (temp)
        {
            if (temp & 1)
                currSubset.push_back(a[idx]);
            idx++;
            temp >>= 1;
        }
        powerset.push_back(currSubset);
    }
}

ll T = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        ll N;
        cin >> N;
        set<int> st;
        a.clear();
        for (ll i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
            st.insert(temp);
        }
        powerSet();
        vector<ll> ans(N + 1, 0);
        ll mxcnt = INT32_MIN;
        ll chefWrite = 0;
        // cout << powerset.size() << endl;
        for (ll i = 1; i < powerset.size(); i++)
        {
            // cout << "subset";
            // for (ll f : powerset[i])
            // 	cout << f;
            // cout << ", ";

            mxcnt = 0;
            for (ll ele : st)
            {
                ll cnt = count(powerset[i].begin(), powerset[i].end(), ele);
                cnt %= mod;
                if (cnt == mxcnt)
                {
                    // cout << chefWrite <<ele<< endl;
                    chefWrite = min(chefWrite, ele);
                    // cout << chefWrite << endl;
                }
                if (cnt > mxcnt)
                {
                    chefWrite = ele;
                    // cout << chefWrite<<" ";
                    mxcnt = cnt;
                }
            }
            // cout << chefWrite;
            ans[chefWrite]++;
        }

        for (ll i = 1; i <= N; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
