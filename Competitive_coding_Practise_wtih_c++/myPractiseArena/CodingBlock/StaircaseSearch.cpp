#include <bits/stdc++.h>
#include "input.h"
using namespace std;
void stariCaseSearch(int (*a)[1000], int n, int m, int key)
{
    int i = 0, j = m - 1;
    while (i < n and j >= 0)
    {
        if (key == a[i][j])
        {
            cout << i + 1 << " " << j + 1 << endl;
            return;
        }
        else if (key > a[i][j])
            i++;
        else
            j--;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 4, m = 5, x = 10;
    int a[1000][1000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            a[i][j] = x++;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int key;
    cin >> key;
    stariCaseSearch(a, n, m, key);
    return 0;
}