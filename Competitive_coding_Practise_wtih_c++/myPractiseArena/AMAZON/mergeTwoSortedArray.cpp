#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int i = 0;
    while (i < n and i < m)
    {
        if (a[i] < b[0])
            i++;
        else
        {
            swap(a[i], b[0]);
            i++;
        }

        for (int k = 0; k < m - 1; k++)
        {
            if (b[k] > b[k + 1])
                swap(b[k], b[k + 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}