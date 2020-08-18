// #include <bits/stdc++.h>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int> a;
int T = 0;
int K = 0;
int dp[10002][10002];

int findres(int i, int j)
{
	if (i == j)
		return 0;
	vector<int> tmp;
	unordered_set<int> st;
	int no_of_table = 0;
	for (int l = i; l < j; l++)
		st.insert(a[l]);

	int inefficiency = 0;
	for (int b : st)
	{
		ll cnt = count(a.begin() + i, a.begin() + j, b);
		// cout <<b<<"cnt" << cnt<<endl;
		if (cnt >= 2)
			inefficiency += cnt;
	}
	for (int l = i; l < j; l++)
	{
		if (count(tmp.begin(), tmp.end(), a[l]) > 0)
		{
			no_of_table++;
			tmp.clear();
		}
		tmp.push_back(a[l]);
	}
	no_of_table++;

	int res = 0;
	res = min(K * no_of_table, K + inefficiency);
	// cout << res << endl;
	return res;
}

int test(int i, int j)
{
	int res = INT32_MAX;

	for (int m = i; m < j; m++)
	{
		int tmp = findres(0, m) + findres(m, j);
		// cout << tmp << endl;
		res = min(tmp, res);
	}
	// cout << res << endl;
	return res;
}



int main()
{
	cin >> T;
	while (T--)
	{
		int N = 0;
		K = 0;
		cin >> N >> K;
		a.clear();
		for (int i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			a.push_back(x);
		}
		int res = test(0, N);
		cout << res << endl;
	}
	return 0;
}

