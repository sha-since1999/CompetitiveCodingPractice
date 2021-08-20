#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    bool flag = 0;
    vector<int> row1, row2;

    for (int i = 1; i <= n; i += 2)
    {

        if (flag)
        {

            if (i + 1 <= n)
                // cout << i + 1 << " ";
                row2.push_back(i + 1);
            // else
            //     // cout << "   ";
            //     row2.push_back(0);
            // cout << i;
            row1.push_back(i);
        }
        else
        {
            // cout << i << " ";
            row2.push_back(i);
            if (i + 1 <= n)
                row1.push_back(i + 1);
            // cout << i + 1;
        }

        flag = flag ? false : true;
        // cout << endl;
    }

    for (int ele : row2)
    {
        cout << ele << " ";
    }
    cout << endl;
    for (int ele : row1)
    {
        cout << ele << " ";
    }

    return 0;
}

// 4Q. Write a program to print the following pattern:

// Example #1
// Input: 8
// Output:
// 1 2
// 4 3
// 5 6
// 8 7

// Q.4 Write a program to print the following pattern:

// Example #1
// Input: 8
// Output:
// 1 4 5 8
// 2 3 6 7