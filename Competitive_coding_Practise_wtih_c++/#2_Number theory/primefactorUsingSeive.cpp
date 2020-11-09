#include <bits/stdc++.h>
using namespace std;
static int primeFactorTable[1000001];
void seivePrimeFactorTable(int n = 100000)
{
    memset(primeFactorTable, -1, sizeof(primeFactorTable));
    for (int i = 2; i <= n; i++)
        if (primeFactorTable[i] == -1)
            for (int j = i; j <= n; j += i)
                if (primeFactorTable[j] == -1)
                    primeFactorTable[j] = i; // now table has been created
}
void printPrimeFactorUsingSeive(int a)
{
    cout << 1 << " ";
    while (a != 1)
        cout << primeFactorTable[a] << " ",
            a /= primeFactorTable[a];
    cout << endl; //just for flash;
}
//**this another simple old approach
void primeFactorisation(int n) //this is simple function just putup to remind
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
                cnt++, n /= i;
            cout << i << "^" << cnt << " ";
        }
    if (n > 1)
        cout << n << "^" << 1 << " ";
    cout << endl; //just to flash output buffer
}
int main()
{
    seivePrimeFactorTable(); //to create table at first
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int l, r;
    while (t--)
    {
        int a;
        cin >> a;
        printPrimeFactorUsingSeive(a); //using optimised method
        primeFactorisation(a);         //using simple method just naive approch
    }
    return 0;
} // everything well tested