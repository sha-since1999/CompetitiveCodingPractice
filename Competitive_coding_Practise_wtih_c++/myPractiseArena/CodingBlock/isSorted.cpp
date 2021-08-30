#include <bits/stdc++.h>
#include "input.h"
using namespace std;
bool isSorted(int *a, int n)
{
    if (n < 2)
        return true;
    if (a[0] < a[1] and isSorted(a + 1, n - 1))
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[] = {1, 2, 3, 9, 5, 6, 7};
    int n = 7;
    cout << isSorted(a, n) << endl;
    return 0;
}