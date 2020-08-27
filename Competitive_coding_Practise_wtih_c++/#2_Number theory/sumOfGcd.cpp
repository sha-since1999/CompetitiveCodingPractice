#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;
static vector<int> phi(1000001);

void phiSeive(int n = 100000) // to find no of co -prime of no up to 10^6 in efficient way
{
    forn(i, n + 1) phi[i] = i; //iota(phi.begin(),phi.end(),0);
    for (int i = 2; i <= n; i++)
        if (phi[i] == i)
            for (int j = i; j <= n; j += i)
                phi[j] /= i, phi[j] *= (i - 1);
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int sumOfGcd1(int n) //naive approach(brute force)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += gcd(i, n);
    return res;
}
int sumOfGcd2(int n) // this calculate the sum  gcd of no 1 to n  to  the n
{                    //O(sqrt(n))
    int res = 0;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            int d1 = i;     //upward
            int d2 = n / i; //downward
            res += d1 * phi[n / d1];
            if (d1 != d2) //to check middle case
                res += d2 * phi[n / d2];
        }
    return res;
}

int main()
{
    phiSeive();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, dim;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        cout << sumOfGcd2(a) << endl; //optimissedsum way
        cout << sumOfGcd1(a) << endl; //using naive aproach
    }
    return 0;
} //well tested