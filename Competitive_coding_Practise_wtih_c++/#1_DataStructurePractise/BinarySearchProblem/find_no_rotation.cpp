#include <bits/stdc++.h>
using namespace std;
void rotate(int *a, int n)
{
    int tmp = a[n - 1];
    for (int i = n - 1; i > 0; i--)
        a[i] = a[i - 1];
    a[0] = tmp;
}

int find_no_of_rotation(int *a, int n, int l, int h)
{
    if (a[l] < a[h])
        return 0;

    int mid, res;
    while (l < h)
    {

        mid = l + (h - l) / 2;
        if (a[mid] > a[(mid + 1) % 8] and a[mid] < a[(mid - 1) % n])
            res = mid;
        else if (a[mid] < a[h])
            h = mid - 1;
        else
            l = mid + 1;

        find_no_of_rotation(a, n, l, h);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[] = {1, 2, 3, 4, 5, 7, 8, 9};
    int n = 8;
    rotate(a, n);
    rotate(a, n);
    rotate(a, n);
    rotate(a, n);

    // cout << find_no_of_rotation(a, n, 0, n - 1) << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
// wrong  code have to verify it