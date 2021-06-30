#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool flag = true;
    for (int i = 1; i <= n; i += 2)

    {
        if (flag)
        {
            cout << i << "  ";
            if (i + 1 <= n)
                cout << i + 1;
        }
        else
        {
            if (i + 1 <= n)
                cout << i + 1 << "  ";
            else
                cout << "    ";
            cout << i << "  ";
        }
        cout << endl;

        flag = flag ? false : true;
    }

    return 0;
}
// 1  2
// 4  3  
// 5  6
// 8  7  
// 9  10
// 12  11  
// 13  14
//     15 