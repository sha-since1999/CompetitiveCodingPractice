#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 4;
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << k++ << " ";

        for (int j = 2 * (n - i) - 1; j > 0; j--)
            cout << "  ";

        for (int j = i; j > 0; j--)
        {
            k--;
            if (k == n)
                continue;
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}

// 1           1
// 1 2       2 1
// 1 2 3   3 2 1
// 1 2 3 4 3 2 1