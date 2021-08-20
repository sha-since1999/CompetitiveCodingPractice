#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    int mx = INT_MIN;
    int n = 6;
    int m = 7;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}