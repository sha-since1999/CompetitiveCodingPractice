#include <bits/stdc++.h>
//#include "sahu.h"
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll N, x;
        cin >> N >> x;
        unordered_map<int, int> mp;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            mp[a]++;
        }
        int mxf = 1;
        int minopr = 0;
        for (auto m : mp)
        {

            if (mxf <= m.second)
            {
                mxf = m.second;
                minopr = 0;
            }
            if (mxf < m.second + mp[m.first ^ x])
            {
                minopr = min(m.second, mp[m.first ^ x]);
                mxf = m.second + mp[m.first ^ x];
            }
            mp.erase(m.first ^ x);
        }
        cout << mxf << " " << minopr << endl;
    }

    return 0;
}