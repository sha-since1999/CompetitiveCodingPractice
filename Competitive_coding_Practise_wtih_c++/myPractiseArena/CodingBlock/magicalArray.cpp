#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, s;
    cin >> n >> m >> k >> s;
    char a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s <= k)
            {
                cout << "NO" << endl;
                return 0;
            }
            if (j != 0)
                s--;
            if (a[i][j] == '#')
                break;
            if (a[i][j] == '.')
                s -= 2;
            if (a[i][j] == '*')
                s += 5;
        }
    }

    cout << "YES" << endl;
    cout << s << endl;

    return 0;
}

// 4 4 5 20
// . . * .
// . # . .
// * * . .
// . # * *