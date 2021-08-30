#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int firstOccu(int *a, int n, int key)
{
    if (n == 1)
        return -1;
    if (a[0] == key)
        return 0;
    int idx = firstOccu(a + 1, n - 1, key);
    if (idx == -1)
        return -1;
    return idx + 1;
}

int lenearSearch(int *a, int i, int n, int key)
{
    if (i == n)
        return -1;
    if (a[i] == key)
        return i;
    return lenearSearch(a, i + 1, n, key);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[] = {1, 3, 5, 5, 2, 5, 6, 2, 5, 43, 3, 46, 6};
    int n = sizeof(a) / sizeof(a[0]);
    // int idx = lenearSearch(a, 0, n - 1, 6 );
    int idx = firstOccu(a, n, 1);
    cout << idx << endl;
    return 0;
}
