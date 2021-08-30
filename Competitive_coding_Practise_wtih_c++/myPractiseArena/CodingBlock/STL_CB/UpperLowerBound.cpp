#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[] = {22, 5, 6, 77, 4, 22, 22, 22, 2, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);
    for (int i : a)
        cout << i << " ";

    int *ptr = lower_bound(a, a + n, 23);
    int *ptrr = upper_bound(a, a + n, 23);
    cout << "\nlower bound: " << *ptr << endl;
    cout << "upper bound: " << *ptrr << endl;
    cout << binary_search(a, a + n, 23) << endl;
    return 0;
}