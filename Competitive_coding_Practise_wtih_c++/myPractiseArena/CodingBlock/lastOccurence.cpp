#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int lastIdx(int *a, int i, int n, int key)
{
    if (i == n - 1)
        return -1;
    int rr = lastIdx(a, i + 1, n, key);
    if (a[i] == key and rr == -1)
        return i;
    return rr;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[] = {1, 3, 5, 7, 32, 43, 42, 4, 6, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    int idx = lastIdx(a, 0, n, 6);
    cout << idx << endl;
    return 0;
}