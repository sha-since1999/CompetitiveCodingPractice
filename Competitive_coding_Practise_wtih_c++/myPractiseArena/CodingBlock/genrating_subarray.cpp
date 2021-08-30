#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 4;
    int a[] = {1, 2, 4, 5};
    cout << "genrating all subarray " << endl;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
                cout << a[k] << " ";
            cout << endl;
        }

    cout << " genrating power set " << endl;
    int x = 1 << n;
    for (int i = 1; i <= x; i++)
    {
        int tmp = i;
        int idx = 0;
        while (tmp)
        {
            if (tmp & 1)
                cout << a[idx] << " ";
            tmp >>= 1;
            idx++;
        }
        cout << endl;
    }
    return 0;
}