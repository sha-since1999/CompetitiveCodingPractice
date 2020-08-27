#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef long long int ll;
vector<vector<ll>> powerset;
vector<ll> a;
void powerSet()
{
    powerset.clear();
    powerset.resize(1);

    for (ll ele : a)
    {
        vector<ll> currSubset;
        ll len = powerset.size();
        for (ll i = 0; i < len; i++)
        {
            currSubset = powerset[i];
            currSubset.push_back(ele);
            powerset.push_back(currSubset);
        }
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
                cnt = cnt > mod ? cnt % mod : cnt;
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
