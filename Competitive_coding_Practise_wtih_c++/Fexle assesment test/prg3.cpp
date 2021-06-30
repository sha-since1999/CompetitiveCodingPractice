#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout << n - j << " ";
        for (int j = 0; j < 4 * i - 2; j++)
            cout << " ";
        if (i == 0)
            for (int j = i + 2; j <= n; j++)
            {

                cout << j << " ";
            }
        else
            for (int j = i + 1; j <= n; j++)
            {

                cout << j << " ";
            }

        cout << endl;
    }

    return 0;
}

// 7 6 5 4 3 2 1 2 3 4 5 6 7
// 7 6 5 4 3 2   2 3 4 5 6 7
// 7 6 5 4 3       3 4 5 6 7
// 7 6 5 4           4 5 6 7
// 7 6 5               5 6 7
// 7 6                   6 7
// 7                       7