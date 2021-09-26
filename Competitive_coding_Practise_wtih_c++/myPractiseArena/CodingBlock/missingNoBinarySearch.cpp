#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int findMissingTerm(int *a, int n)
{
    int l = 0, h = n - 1;
    while (l < h)
    {
        int mid = (l + h) / 2;
        if (a[mid] - a[l] > a[h] - a[mid])
            h = mid;
        else if (a[mid] - a[l] < a[h] - a[mid])
            l = mid;
        if (l + 1 == h)
            break;
    }

    return a[l] + (a[h] - a[l]) / 2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << findMissingTerm(a, n);
    return 0;
}
// 5
// 5 7 9 11 15
// o/p= 13