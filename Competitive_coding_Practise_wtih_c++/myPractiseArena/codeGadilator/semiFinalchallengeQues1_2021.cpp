#include <iostream>
#include "sahu.h"
using namespace std;
#define int long long
int orgN;
int finalAns = 0;
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

void func(int n)
{
    int ans = INT32_MAX;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int a = n / i;
            int b = i;
            if (!isPrime(a))
            {

                ans = a;
                break;
            }
            else
            {
                ans = b;
                break;
            }

            ans = min(ans, b);
        }
    }
    // cout << n << " " << ans << endl;
    if (isPrime(ans))
    {
        finalAns += (orgN + (orgN / ans));
        // cout << "finalans" << n << " " << (orgN + (orgN / ans)) << endl;
        return;
    }
    else
    {
        finalAns += (orgN / ans);
        func(ans);
    }
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        orgN = N;
        finalAns += 1;
        if (N > 1)
            func(N);
    }
    cout << finalAns;
    return 0;
}