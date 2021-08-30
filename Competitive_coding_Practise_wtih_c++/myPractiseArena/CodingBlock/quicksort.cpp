#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int partition(int *a, int i, int j)
{
    int p = a[i];
    while (i < j)
    {
        while (a[i] < p)
            i++;
        while (a[j] > p)
            j--;
        swap(a[i], a[j]);
    }
    swap(a[i], p);
    return i;
}
void quicksort(int *a, int i, int j)
{
    if (i < j)
    {
        int p = partition(a, i, j);
        quicksort(a, i, p - 1);
        quicksort(a, p + 1, j);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[] = {1, 5, 3, 6, 9, 12, 33, 95, 23};
    int n = sizeof(a) / sizeof(a[0]);
    quicksort(a, 0, n - 1);
    for (int x : a)
        cout << x << " ";
    return 0;
}