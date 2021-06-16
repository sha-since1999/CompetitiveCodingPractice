#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
ll fib(ll n)
{
    ll ans = pow((1 + sqrtl(5)), n) - pow((1 - sqrtl(5)), n);
    ans /= (pow(2, n) * sqrtl(5));
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fib(3) << endl;

    return 0;
}