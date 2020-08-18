#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int consecutiveSumPrime(int limit)
{
    vector<bool> mark(limit + 1, true);

    for (ll p = 2; p * p <= limit; p++)
        if (mark[p])
            for (ll i = p * 2; i <= limit; i += p)
                mark[i] = false;

    mark.shrink_to_fit();

    vector<int> prime(1, 2);
    for (ll p = 3; p <= limit; p++)
        if (mark[p])
            prime.push_back(prime.back() + p);

    prime.shrink_to_fit();
    int ans = -1;
    for (int pp : prime)
        if (mark[pp] and pp <= limit)
        {
            // cout << pp << " ";
            ans++;
        }

    return ans;
}
int main()
{
    ll n = 1234000;
    cout << "Primes smaller than " << n << ": ";
    cout << consecutiveSumPrime(n) << endl;
    return 0;
}