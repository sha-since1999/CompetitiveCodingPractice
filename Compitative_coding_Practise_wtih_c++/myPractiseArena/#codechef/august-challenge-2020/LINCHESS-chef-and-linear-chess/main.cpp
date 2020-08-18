// #include <stdc++>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t;
int main()
{
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> v(n + 1, INT_MAX);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		sort(v.begin(), v.end());

		int mn = -1;
		for (int i = 0; (v[i] <= k / 2 and i < n); i++)
			if (k % v[i] == 0)
				mn = v[i];

		cout << mn << endl;
	}
	return 0;
}
