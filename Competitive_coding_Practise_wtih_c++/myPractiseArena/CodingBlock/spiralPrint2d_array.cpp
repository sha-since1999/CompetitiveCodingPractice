#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n = 5, m = 5;
    cin >> n >> m;
    int x = 10;
    int a[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = x++;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "<<<<_______Spiral printing of 2d Array______>>>>" << endl;
    int s_i = 0, e_i = n, s_j = 0, e_j = m;

    while (s_i < e_i or s_j < e_j)
    {

        //top row;
        for (int j = s_j; j < e_j; j++)
            cout << a[s_i][j] << " ";

        s_i++;
        //right col
        if (e_j - 1 >= s_j)
            for (int i = s_i; i < e_i; i++)
            {
                cout << a[i][e_j - 1] << " ";
            }
        e_j--;

        //bottom row
        if (e_i - 1 > s_i)
            for (int j = e_j - 1; j >= s_j; j--)
            {
                cout << a[e_i - 1][j] << " ";
            }
        e_i--;

        // left col;
        if (s_j < e_j)
            for (int i = e_i - 1; i >= s_i; i--)
                cout << a[i][s_j] << " ";
        s_j++;
    }

    return 0;
}
// well tested
// everything is  fine but i dont  know why it's not working well for 3*5 matrix in my compiler