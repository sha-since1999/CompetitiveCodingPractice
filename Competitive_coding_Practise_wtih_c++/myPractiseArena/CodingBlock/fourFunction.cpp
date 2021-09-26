#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
int A(int x)
{
    int cnt = 0;
    for (int i = 1; i <= x; i++)
        if (gcd(i, x) == 1)
            cnt++;

    return cnt;
}
int B(int x)
{
    int ans = 0;
    for (int i = 1; i * i <= x; i++)
        if (x % i == 0)
            ans += A(i);

    return ans;
}
int C(int x)
{
    x = B(x);
    int ans = 0;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
                cnt++, x /= i;
            ans += cnt;
        }
    }
    ans += x;

    return ans;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int d;
        int ans = 0;
        cin >> d;
        for (int i = 2; i <= d; i++)
        {
            ans += C(i);
        }

        cout << ans << endl;
    }

    return 0;
}


