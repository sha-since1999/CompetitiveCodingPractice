#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    int mx = INT_MIN;
    int n = 4;
    int m = 4;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            mx = max(a[i][j], mx);
        }
    }
    a[0][0] = a[0][m - 1] = a[n - 1][0] = a[n - 1][m - 1] = mx;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}