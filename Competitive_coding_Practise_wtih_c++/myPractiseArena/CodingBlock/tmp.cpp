#include <bits/stdc++.h>
using namespace std;
int nCr(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    else
    {
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
}
int main()
{
    int n, curr, jump;
    cin >> n >> curr >> jump;
    int ans = 0;
    while (jump > 1)
    {
        ans += nCr(n - curr, jump);

        jump--;
    }
    cout << ans << endl;
}
