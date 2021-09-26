#include <bits/stdc++.h>
// #include "input.h"
using namespace std;
int main()
{

    int m;
    cin >> m;
    int a[m][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    bool flag = false;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                if (j + 3 < m and a[i][j + 1] == 0 and a[i][j + 2] == 0)
                {
                    flag = true;
                    break;
                }
                if (i + 3 < m and a[i + 1][j] == 0 and a[i + 2][j] == 0)
                {
                    flag = true;
                    break;
                }
            }
            if (a[i][j] == -1)
            {
                if (j + 4 < m and a[i][j + 1] == 2 and a[i][j + 2] == 5 and a[i][j + 3] == 7)
                {
                    flag = true;
                    break;
                }
                if (i + 4 < m and a[i + 1][j] == 4 and a[i + 2][j] == 6 and a[i + 3][j] == 9)
                {
                    flag = true;
                    break;
                }
            }
            if (a[i][j] == 2)
            {
                if (j + 4 < m and a[i][j + 1] == 4 and a[i][j + 2] == 6 and a[i][j + 3] == 9)
                {
                    flag = true;
                    break;
                }
                if (i + 4 < m and a[i + 1][j] == 4 and a[i + 2][j] == 6 and a[i + 3][j] == 9)
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            cout << "Yes" << endl;
        break;
    }

    return 0;
}