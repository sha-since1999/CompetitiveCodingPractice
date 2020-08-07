#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
static vector<int> phi(1000001);

// below there some helping function of ETF also
int power2(int b, int a) //binary exponentiation    O(log n)
{
    if (a == 0)
        return 1; // this is addition to create it efficient
    int res = 1;
    while (a)
    {
        if (a % 2)
            res *= b, a--;
        a /= 2, b *= b;
    }
    return res;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int isPrime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
//Euler's totient functions
int phiETF(int p, int x = 1) // to calculate no co-prime to    ***here p should be prime****
{                            //phi(p)= p-1  and phi(p^x)=p^(x-1)*(p-1);
    if (p < 2)
        return 0;
    // if (!isPrime(p))
    //     return -1;
    return power2(p, x - 1) * (p - 1);
}
int phi1(int n) // naive approach to find no of co prime
{
    int cnt = 0;
    for (int i = 0; i <= n; i++)
        if (gcd(i, n) == 1)
            cnt++;
    return cnt;
}
int phi2(int n) // this is also etf but it for all nos (Euler totient function)  O(sqrt(n))
{
    int res = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            res /= i, res *= (i - 1); //  phi(n)=N∑((pi-1)/pi);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        res /= n, res *= (n - 1); //check if divisor is greater than sqrt(n)  means itself n
    return res;
}
void phi3Seive(int n = 100000) // to find no of co -prime of no up to 10^6 in efficient way  O(nlog(logn))
{
    forn(i, n + 1) phi[i] = i; //iota(phi.begin(),phi.end(),0);
    for (int i = 2; i <= n; i++)
        if (phi[i] == i)
            for (int j = i; j <= n; j += i)
                phi[j] /= i, phi[j] *= (i - 1);
}
int main()
{
    // primeSeive();
    // seivePrimeFactorTable();
    phi3Seive();

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, dim;
    cin >> t;
    // int a, b;
    int l, r;
    while (t--)
    {
        int a, n;
        cin >> a;
        cout << phi[a] << endl;
        cout << phi1(a) << endl;
        cout << phi2(a) << endl;
    }
    return 0;
}
