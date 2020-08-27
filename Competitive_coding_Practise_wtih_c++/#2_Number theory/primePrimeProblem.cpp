#include <bits/stdc++.h>
using namespace std;
vector<bool> primes(90000001, 1);
vector<int> countPrimes(90000001);

void primeSeive()
{
    int n = 90000000;
    primes[1] = primes[0] = 0;
    for (int i = 2; i * i <= n; i++)
        if (primes[i])
            for (int j = i * i; j <= n; j += i)
                primes[j] = 0;
    for (int k = 2; k <= n; k++) //to cteate table of prime count under given no.
        countPrimes[k] = countPrimes[k - 1] + primes[k];
}
int noOfPrimePrime(int l, int r)
{
    int cnt = 0;
    for (int i = l; i <= r; i++)
        if (primes[countPrimes[i]])
            cnt++;
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    primeSeive();
    int t, l, r;
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        cout << noOfPrimePrime(l, r) << endl;
    }

    return 0;
}

// problem statement :-  to find no of prime-prime no in the given range
// prime- prime no :are those no form 1 to that no (with inclusive) ,no of prime no is prime