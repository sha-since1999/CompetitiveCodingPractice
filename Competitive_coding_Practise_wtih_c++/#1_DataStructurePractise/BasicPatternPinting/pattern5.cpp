#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int j;
        for (j = 1; j <= n - i; j++)
            cout << " ";
        for (j = 1; j < (2 * i); j++)
            cout << "*";
        cout << endl;
    }

    return 0;
}

// if you stuck with the loop then try to use loop from x=1 to x=n only

//     *
//    ***
//   *****
//  *******
// *********