#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
            cout << "  ";
        for (int j = 0; j <= i; j++)
        {
            cout << j + i + 1 << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << 2 * (i)-j << " ";
        }
        cout << endl;
    }

    return 0;
}

//             1
//           2 3 2
//         3 4 5 4 3
//       4 5 6 7 6 5 4
//     5 6 7 8 9 8 7 6 5