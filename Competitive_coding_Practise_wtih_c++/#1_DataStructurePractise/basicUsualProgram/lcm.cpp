#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b) // basic method
{
    int lcm = a > b ? a : b;
    while (1)
    {
        if ((lcm % a) == 0 and (lcm % b) == 0)
            break;
        lcm++;
    }

    return lcm;
}
int hcf(int a, int b) //just helper
{
    if (!b)
        return a;
    return hcf(b, a % b);
}
int LCM(int a, int b) // alternative approach
{
    return a * b / hcf(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;
    cout << LCM(a, b) << endl;
    return 0;
}