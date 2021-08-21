#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        int k = i + 1;
        for (int j = 0; j < 2 * (n - i); j++)
            cout << "  ";
        for (int j = 0; j <= i; j++)
            cout << k-- << " ";
        for (int j = 0; j < 2 * i - 1; j++)
            cout << "  ";
        for (int j = 0; j <= i; j++)
        {
            if (i == 0)
                continue;
            cout << ++k << " ";
        }
        cout << endl;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        int k = i + 1;
        for (int j = 0; j < 2 * (n - i); j++)
            cout << "  ";
        for (int j = 0; j <= i; j++)
            cout << k-- << " ";
        for (int j = 0; j < 2 * i - 1; j++)
            cout << "  ";
        for (int j = 0; j <= i; j++)
        {
            if (i == 0)
                continue;
            cout << ++k << " ";
        }
        cout << endl;
    }

    return 0;
}
//             1
//         2 1   1 2
//     3 2 1       1 2 3
// 4 3 2 1           1 2 3 4
//     3 2 1       1 2 3
//         2 1   1 2
//             1