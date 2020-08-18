#include <bits/stdc++.h>
// #include<iostream>
// #include<stdio.h>
// #include<vector>
// #include<algorithm>

using namespace std;
typedef long long ll;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int chef, rick;
		cin >> chef >> rick;
		int chefwins = chef > 9 * floor(chef / 9) ? chef / 9 + 1 : chef / 9;
		int rickwins = rick > 9 * floor(rick / 9) ? rick / 9 + 1 : rick / 9;
		chefwins < rickwins ? cout << "0 " << chefwins << endl : cout << "1 " << rickwins << endl;
	}
	return 0;
}
