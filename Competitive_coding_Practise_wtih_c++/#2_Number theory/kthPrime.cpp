#include <bits/stdc++.h>
using namespace std;
vector<bool>primes(90000001, 1);
vector<int> primeTable;

void primeSeive()
{
    int n = 90000000;
    // memset(primes, 1, sizeof(primes));
    primes[1] = primes[0] = 0;
    for (int i = 2; i * i <= n; i++)
        if (primes[i])
            for (int j = i * i; j <= n; j += i)
                primes[j] = 0;
    for (int k = 2; k <= n; k++) //to cteate table of prime
        if (primes[k])
            primeTable.push_back(k);
}
int main()
{

    primeSeive();

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << primeTable[n - 1] << endl;
    }

    return 0;
}
