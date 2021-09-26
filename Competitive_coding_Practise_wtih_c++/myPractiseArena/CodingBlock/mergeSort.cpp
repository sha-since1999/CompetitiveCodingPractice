#include <bits/stdc++.h>
#include "input.h"
using namespace std;
void merge(int *a, int l, int mid, int h)
{
    int c[h + 1];
    int j = mid + 1,i;
    int k = i = l;
    while (i <= mid and j <= h)
    {
        if (a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }
    while (i <= mid)
        c[k++] = a[i++];
    while (j <= h)
        c[k++] = a[j++];
    for (int x = l; x <= h; x++)
        a[x] = c[x];
}
void mergeSort(int *a, int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[] = {1, 5, 3, 6, 9, 12, 33, 95, 23};
    int n = sizeof(a) / sizeof(a[0]);
    mergeSort(a, 0, n - 1);
    for (int x : a)
        cout << x << " ";

    return 0;
}