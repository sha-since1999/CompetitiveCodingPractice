#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 4, m = 4, x = 10;
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

    //firstly reverse each row
    for (int i = 0; i < n; i++)
    {
        int j = 0, k = m - 1;
        while (j < k)
            swap(a[i][j++], a[i][k--]);
    }

    // reverse each row useing stl;
    // for (int i = 0; i < n; i++)
    //     reverse(a[i], a[i] + n);

    //take transpose of matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j > i)
                swap(a[i][j], a[j][i]);
        }
    }

    cout << "  90 degree anticlock wise rotation" << endl;
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