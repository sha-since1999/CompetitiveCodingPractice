#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        double x, y, z;
        cin >> x >> y >> z;
        double h = y - z;
        double t = sqrt(2 * 10.0 * h);
        double ans = (x * 10) / t;
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}