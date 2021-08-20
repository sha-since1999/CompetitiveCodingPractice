#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mx = INT32_MIN, pp = 0;
    int val1 = 0, val2 = 0;
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            pp = a[i] * a[j];
            if (pp > mx)
            {
                mx = pp;
                val1 = i, val2 = j;
            }
        }
    }

    cout << a[val1] + a[val2] << endl;
    return 0;
}