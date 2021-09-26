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
        ll n, a, b;
        cin >> n >> a >> b;
        char c;
        int x=0, y=0;
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            if (c == '1')
                y++;
            else
                x++;
        }
        cout << x * a + y * b << endl;
    }
    return 0;
}