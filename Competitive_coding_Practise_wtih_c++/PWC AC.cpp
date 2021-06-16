#include <bits/stdc++.h>
using namespace std;
static int primeFactorTable[10000001];
void seivePrimeFactorTable(int n = 1000000)
{
    memset(primeFactorTable, -1, sizeof(primeFactorTable));
    for (int i = 2; i <= n; i++)
        if (primeFactorTable[i] == -1)
            for (int j = i; j <= n; j += i)
                if (primeFactorTable[j] == -1)
                    primeFactorTable[j] = i; 
}
void printPrimeFactorUsingSeive(int a)
{
    cout << 1 << " ";
    while (a != 1)
        cout << primeFactorTable[a] << " ",
            a /= primeFactorTable[a];
    cout << endl; 
}

void primeFactorisation(int n) 
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
    cout << endl; 
}
int main()
{
    seivePrimeFactorTable(); 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int l, r;
    while (t--)
    {
        int a;
        cin >> a;
        printPrimeFactorUsingSeive(a); 
        primeFactorisation(a);        
    }
    return 0;
}