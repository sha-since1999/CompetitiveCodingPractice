#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 3, m  = 5;
    int x = 1;
    int a[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = x++;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "<<______wave printing of an array____>>" << endl;

    for (int j = 0; j < m; j++)
    {
        if (j & 1)
            for (int i = n - 1; i >= 0; i--)
            {
                cout << a[i][j] << " ";
            }
        else
            for (int i = 0; i < n; i++)
            {
                cout << a[i][j] << " ";
            }
        cout << endl;
    }

    return 0;
}