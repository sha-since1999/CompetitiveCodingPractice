#include <bits/stdc++.h>
using namespace std;

int lowerBound(int *a, int key, int l, int h)
{
    int res, mid;
    while (l < h)
    {
        mid = (l + h) / 2;

        if (a[mid] == key)
        {
            res = mid;
            h = mid - 1;
        }
        else if (a[mid] < key)
            l = mid + 1;
        else
            h = mid - 1;

        lowerBound(a, key, l, h);
    }
    return res;
}
int upperBound(int *a, int key, int l, int h)
{
    int res, mid;
    while (l < h)
    {
        mid = (l + h) / 2;

        if (a[mid] == key)
        {
            res = mid;

            l = mid + 1;
        }
        else if (a[mid] < key)
            l = mid + 1;
        else
            h = mid - 1;

        lowerBound(a, key, l, h);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[] = {1, 3, 3, 3, 5, 6, 7, 9};
    cout << lowerBound(a, 3, 0, 7) << endl;
    cout << upperBound(a, 3, 0, 7) << endl;
    auto x = lower_bound(a, a + 8, 3) - a;
    auto y = upper_bound(a, a + 8, 3) - a; // this funciton return  index of just greater value
    cout << x << " " << y << endl;

    cout << "no OF Occurence : " << y - x << endl;

    return 0;
}