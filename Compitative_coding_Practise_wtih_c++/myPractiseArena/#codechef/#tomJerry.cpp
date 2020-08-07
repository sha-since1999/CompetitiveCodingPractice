#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
static ull jerryWinsCount = 0;
ull tomJerry(ull TS)
{
    ull JS;
    if (TS % 2 == 0)
    {
        tomJerry(TS / 2);
        return jerryWinsCount;
    }
    else
    {
        jerryWinsCount = 0;
        JS = 2;
        while (JS <= TS)
        {
            jerryWinsCount++;
            JS += 2;
        }
    }
    return jerryWinsCount;
}

ull TS = 0;
ll T = 0;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> TS;
        cout << tomJerry(TS) << endl;
    }
    return 0;
}