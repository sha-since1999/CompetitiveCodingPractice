#include <bits/stdc++.h>
#include "input.h"
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, h = n - 1, mid = 0;
    while (mid <= h)
    {
        switch (a[mid])
        {
        case 0:
            swap(a[mid++], a[l++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(a[mid++], a[h--]);
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

// 5
// 0 1 2 0 1
// o/p = 0011 2