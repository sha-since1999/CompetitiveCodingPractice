#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull nth_catalon(int n)
{
    if (n <= 1)
        return 1;
    ull res = 0;
    for (int i = 0; i < n; i++)
        res += nth_catalon(i) * nth_catalon(n - 1 - i);
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 10; i++)
        cout << nth_catalon(i) << " ";

    return 0;
}
