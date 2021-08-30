#include <bits/stdc++.h>
#include "input.h"
using namespace std;
void deleteHeap(int *a, int n)
{

    int i = 1;
    int j = 2 * i;
    swap(a[i], a[n]);
    while (j < n and a[i] < a[j])
    {
        if (a[j] < a[j + 1])
            j++;
        swap(a[i], a[j]);
        i = j;
        j = 2 * i;
    }
}
void createHeap(int *a, int i)
{
    int j = i / 2;
    while (j > 0 and a[j] < a[i])
    {
        swap(a[i], a[j]);
        i = j;
        j = i / 2;
    }
}
void heapsort(int *a, int n)
{
    for (int i = 2; i < n; i++)
    {
        createHeap(a, i);
    }
    for (int i = 0; i < n - 2; i++)
    {
        deleteHeap(a, n - 1 - i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[] = {0, 1, 233, 23, 34, 4, 45, 5, 3, 22, 30};
    int n = sizeof(a) / sizeof(a[0]);

    heapsort(a, n);
    for (int x : a)
        cout << x << " ";

    return 0;
}