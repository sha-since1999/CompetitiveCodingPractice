// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
const int mod = 1e9 + 7;
using namespace std;
typedef long long int ll;
vector<unordered_map<int, int>> powerset;
vector<ll> a;

void powerSet()
{
	int x = 1 << a.size();
	powerset.clear();
	for (int i = 1; i < x; i++)
	{
		int temp = i;
		int idx = 0;
		unordered_map<int, int> mp;
		while (temp)
		{
			if (temp & 1)
			{
				mp[a[idx]]++;
			}
			idx++;
			temp >>= 1;
		}
		powerset.push_back(mp);
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
		a.clear();
		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			a.push_back(temp);
		}
		powerSet();
		vector<ll> ans(N + 1, 0);
		ll mxcnt = INT32_MIN;
		int chefWrite = 0;
		for (auto mp : powerset)
		{
			mxcnt = 0;
			for (auto p : mp)
			{
				if (p.second == mxcnt)
					chefWrite = min(chefWrite, p.first);

				else if (p.second >= mxcnt)
				{
					chefWrite = p.first;
					mxcnt = p.second;
				}
			}
			ans[chefWrite]++;
			if (ans[chefWrite] >= mod)
				ans[chefWrite] %= mod;
		}
		for (int i = 1; i <= N; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}
