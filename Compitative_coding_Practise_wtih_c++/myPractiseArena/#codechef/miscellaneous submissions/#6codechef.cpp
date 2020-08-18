#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull TS = 0;
ull T = 0;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> TS;
        while (TS % 2 == 0)
        {
            TS /= 2;
        }
    cout << (TS - 1) / 2 << endl;
    }
    return 0;
}