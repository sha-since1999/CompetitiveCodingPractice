#include <bits/stdc++.h>
using namespace std;
typedef longlong ll;

int main()
{

    ll n, k;
    cin >> n >> k;
    ll ctr = 0;
    while (n % 2 == 0)
    {
        ctr++;
        n /= 2;
    }
    k -= ctr;
    ctr = 0;
    ll sum = 0;
    ll mul = 1;
    for (int i = 1; i <= 25; i++)
    {
        sum += mul;
        mul *= 16;
    }
    while (sum % 2 == 0)
    {
        ctr++;
        sum /= 2;
    }
    ll count = k / (4 + ctr);
    k = k % 4;
    if (k != 0)
        count++;
    cout << count;
    return 0;
}