#include <bits/stdc++.h>
#include "sahu.h"
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v;
        v.push_back(-1);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        int x = v[1], y = v[2];
        int count = 1;
        while (v[x] != v[1] || v[y] != v[2])
        {
            y = v[y];
            x = v[x];
            count++;
        }
        cout << count << endl;
    }

    return 0;
}
// 1
// 6
// 3 6 5 4 1 2