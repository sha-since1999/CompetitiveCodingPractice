#include <iostream>
using namespace std;
typedef long long int ll;
int t;
int main()
{
	cin >> t;
	while (t--)
	{
		int h, p, war = 0;
		cin >> h >> p;

		while (p > 0)
		{
			war += p;
			p = p >> 1;
		}

		if (war >= h)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
	return 0;
}