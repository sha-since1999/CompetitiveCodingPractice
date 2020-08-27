#include <bits/stdc++.h>
// #include "sahu.h"
using namespace std;
typedef long long ll;
int main()
{

    int T;
    cin >> T;
    ll N, S;

    while (T--)
    {
        cin >> S >> N;
        ll count = 0;

        if (S >= N)
        {
            count += floor(S / N);
            S = S % N;
        }
        if (S == 0)
        {
            cout << count << endl;
        }
        else if ((S & 1) != 1 || S == 1)
        {
            count += 1;
            cout << count << endl;
        }
        else
        {
            count += 2;
            cout << count << endl;
        }
    }

    return 0;
}
