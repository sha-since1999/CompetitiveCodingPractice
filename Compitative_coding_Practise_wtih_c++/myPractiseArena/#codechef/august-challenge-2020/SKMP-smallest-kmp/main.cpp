// #include<bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <stdlib.h>
using namespace std;
int T = 0;
int main()
{
	cin >> T;
	while (T--)
	{
		string s, p;
		cin >> s >> p;
		vector<int> h(26, 0);
		for (char c : s)
			h[c - 97]++;
		for (char c : p)
			h[c - 97]--;

		bool flag = 1;
		for (int i = 0; i < 26; i++)
		{
			if (h[i] > 0)
			{
				char c = i + 97;
				if (c >= p[0] && flag)
				{
					int k = 1;
					if (c == p[1])
					{
						while (c == p[k])
							k++;
					}
					if (c > p[k])
					{
						cout << p;
						flag = false;
						while (h[i]-- > 0)
							cout << c;
					}

					else if (c < p[k])
					{
						while (h[i]-- > 0)
							cout << c;
						cout << p;
						flag = false;
					}
				}
				else
					while (h[i]--)
						cout << c;
			}
		}
		if (flag)
			cout << p;
		cout << endl;
	}
	return 0;
}