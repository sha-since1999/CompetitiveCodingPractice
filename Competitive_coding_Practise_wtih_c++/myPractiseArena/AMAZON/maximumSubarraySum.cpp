#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        maxSum = max(sum, maxSum);
        if (a[i] > sum)
            sum = 0;
    }
    cout << maxSum << endl;
    return 0;
}

// 8
// -2 -3 4 -1 -2 1 5 -3
// o/p= 7