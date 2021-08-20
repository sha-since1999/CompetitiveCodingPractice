#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int main()
{
    int num;
    cin >> num;
    int space;

    int i, j, lterm, rterm;

    lterm = 1;

    rterm = num * num + 1;

    for (i = num; i > 0; i--)
    {

        for (space = num; space > i; space--)
            cout << "  ";

        for (j = 1; j <= i; j++)
            cout << lterm++ << " ";

        for (j = 1; j <= i; j++)
            cout << rterm++ << " ";

        rterm = rterm - (i - 1) * 2 - 1;
        cout << endl;
    }
}

// i/p 4
// o/p
// 1 2 3 4 17 18 19 20
//   5 6 7 14 15 16
//     8 9 12 13
//       10 11
