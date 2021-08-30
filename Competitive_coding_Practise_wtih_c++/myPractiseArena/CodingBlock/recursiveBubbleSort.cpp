#include <bits/stdc++.h>
#include "input.h"
using namespace std;

void bubbleSort(int *a, int n)
{
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            swap(a[i], a[i + 1]);

    bubbleSort(a, n - 1);
}

void bubble_sort_recursive(int *a, int j, int n)
{
    if (n == 1)
        return;
    if (j == n - 1)
        return bubble_sort_recursive(a, 0, n - 1);
    if (a[j] > a[j + 1])
        swap(a[j], a[j + 1]);
    bubble_sort_recursive(a, j + 1, n);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[] = {1, 3, 5, 7, 32, 43, 42, 4, 6, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    // bubbleSort(a, n);
    bubble_sort_recursive(a, 0, n);
    for (int x : a)
        cout << x << " ";
    return 0;
}