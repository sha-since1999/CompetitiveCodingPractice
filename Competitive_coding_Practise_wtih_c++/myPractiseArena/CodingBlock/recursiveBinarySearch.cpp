#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int binarySearch(int *a, int l, int h, int key)
{
    if (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (a[mid] == key)
            return mid;
        if (a[mid] < key)
            return binarySearch(a, mid + 1, h, key);

        return binarySearch(a, l, mid - 1, key);
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int a[] = {1, 3, 5, 7, 32, 43, 42, 4, 6, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);
    for (int x : a)
        cout << x << " ";
    int idx = binarySearch(a, 0, n - 1, 3);
    cout << idx << endl;
    return 0;
}