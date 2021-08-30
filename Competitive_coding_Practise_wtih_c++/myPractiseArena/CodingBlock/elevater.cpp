#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    int n = 0, sum = 0;
    while (cin >> n)
    {
        sum += n;
    }
    if ((sum & 1))
        cout << sum / 2 << endl;
    else
        cout << "not possible to balance" << endl;
    return 0;
}
