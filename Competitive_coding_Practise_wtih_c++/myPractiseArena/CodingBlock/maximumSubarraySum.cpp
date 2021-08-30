#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[] = {-4, 1, 3, -2, 6, 2, -8, -9, 4};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "genrating all subarray (naive approach : log(n^3)" << endl;
    int mxsum = INT32_MIN, sum, l, r;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
                sum += a[k];
            if (sum > mxsum)
            {
                mxsum = sum;
                l = i;
                r = j;
            }
        }

    cout << "max_sum: " << mxsum << endl;
    cout << "subarrray: ";
    for (int k = l; k <= r; k++)
        cout << a[k] << " ";

    cout << "log(n) approach kadane algo: " << endl;
    sum = INT32_MIN;
    mxsum = INT32_MIN;
    l = 0;
    r = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum < 0)
            sum = 0;

        sum += a[i];
        if (sum > mxsum)
            mxsum = sum;
    }

    cout << "MAX Sum using kadane algo: " << mxsum << endl;

    return 0;
}