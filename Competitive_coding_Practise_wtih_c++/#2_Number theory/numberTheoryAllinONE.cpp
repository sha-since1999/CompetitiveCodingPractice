#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define N 101
#define mod 1000000007
static vector<bool> primes(10000001, true);
static int primeFactorTable[1000001];
static vector<int> phi(1000001);
int I[N][N], A[N][N];

int isPrime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
void primeSeive(int maxN = 10000000)
{
    primes[1] = primes[0] = false;
    for (int i = 2; i * i <= maxN; i++)
        if (primes[i])
            for (int j = i * i; j <= maxN; j += i)
                primes[j] = false;
    return;
}
int power1(int a, int b) //naive approach to power of number o(n)
{
    int res = 1;
    while (b--)
        res *= a;
    return res;
}
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
int powerr(int a, int n) // this recursive method of binary exponentiation
{
    if (n == 0)
        return 1;
    int res = powerr(a, n / 2);
    if (n & 1)
        return a * res * res;
    return res * res;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
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

    return;
}
int powerModulo(int b, int a, int m) // for p^x mod y
{
    int res = 1;
    while (a)
        if (a % 2)
            res = (res * a) % m, a--;
        else
            a /= 2, b = (b * b) % m;
    return res;
}

//matrix Multiplication below

void multiplicaton(int a[][N], int b[][N], int n)
{
    int c[n][n];
    forn(i, n)
        forn(j, n)
    {
        c[i][j] = 0;
        forn(k, n) c[i][j] += a[i][k] * b[k][j];
    }
    forn(i, n)
        forn(j, n)
            a[i][j] = c[i][j];
}

void powerOfMatrix(int a[][N], int dim, int n)
{
    forn(i, dim)
        forn(j, dim) if (i == j)
            I[i][j] = 1;
    else I[i][j] = 0;

    while (n)
        if (n % 2)
            multiplicaton(I, a, dim), n--;
        else
            multiplicaton(a, a, dim),
                n /= 2;
    forn(i, dim)
        forn(j, dim)
            a[i][j] = I[i][j];

    return;
}
void printMatrix(int a[][N], int dim)
{
    forn(i, dim)
    {
        forn(j, dim)
                cout
            << a[i][j] << " ";
        cout << endl;
    }
    return;
}
// matrix multiplication function above

// void segmentedSeive(int l, int r)
// {
//     if (l == 1)
//         l++;
//     int n = r - l + 1;
//     int arr[n + 1];
//     memset(arr, 1, sizeof(arr));
//     int j = 0;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (primes[i])
//         {
//             j = (l / i) * i;
//             if (j <= l)
//                 j += i;
//             for (; j <= r; j += i)
//                 arr[j - l] = 0;
//         }
//     }
//     for (int j = 0; j <= n; j++)
//         if (arr[j + l - 1])
//             cout << j + l - 1 << " ";

//     cout << endl;
// } // there is problem with this have to check it completely

void findNthElement(int f1, int f2, int n) //find n th fibonacci element
{
    int a[N][N] = {{0, 1}, {1, 1}};
    int f[N][N] = {{f1, f2}, {1, 1}};
    powerOfMatrix(a, 2, n - 1);
    multiplicaton(f, a, 2);
    cout << f[0][0] << endl;
}
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
int etf(int p, int x = 1) // to calculate no co-prime to    ***here p should be prime****
{
    if (p < 2)
        return 0;
    if (!isPrime(p)) //phi(p)= p-1  and phi(p^x)=p^(x-1)*(p-1)
        return -1;
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
int phi2(int n) // this is also etf but it for all nos (Euler totient function)
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
void phiSeive(int n = 100000) // to find no of co -prime of no up to 10^6 in efficient way
{
    forn(i, n + 1) phi[i] = i; //iota(phi.begin(),phi.end(),0);
    for (int i = 2; i <= n; i++)
        if (phi[i] == i)
            for (int j = i; j <= n; j += i)
                phi[j] /= i, phi[j] *= (i - 1);
}
int sumOfGcd1(int n) //naive approach(brute force)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += gcd(i, n);
    return res;
}
int getsameGcdCount(int n, int d) // this  no. of no. having gcd d == no. of no. which is coprime with (n/d)
{
    return phi[n / d];
}
int sumOfGcd2(int n) // this calculate the sum  gcd of no 1 to n  to  the n
{                    //O(sqrt(n))
    int res = 0;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            int d1 = i;     //upward
            int d2 = n / i; //downward
            res += d1 * getsameGcdCount(n, d1);
            if (d1 != d2) //to check middle case
                res += d2 * getsameGcdCount(n, d2);
        }
    return res;
}
int noOfDivisor(int n)
{
    int total_divisor = 1;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
                cnt++, n /= i;
            total_divisor *= (cnt + 1);
        }
    return total_divisor;
}

int main()
{
    primeSeive();
    // seivePrimeFactorTable();
    phiSeive();

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, dim;
    cin >> t;
    // int a, b;
    int l, r;
    while (t--)
    {
        // int a, n;
        // cin >> a;
        // cout << sumOfGcd2(a) << endl; //optimissedsum way
        // cout << sumOfGcd1(a) << endl; //using naive aproach

        // cout << noOfDivisor(a) << endl;
        // cin >> a;
        // cout << phi[a] << endl;
        // cout << phi1(a) << endl;

        // cin >> a >>n;
        // printPrimeFactorUsingSeive(a);
        // cout << etf(a, n) << endl;

        // int f1, f2;
        // cin >> f1 >> f2 >> n;
        // findNthElement(f1, f2, n);

        cin >> l >> r;
        segmentedSeive(l, r);

        // cin >> dim;
        // forn(i, dim)
        //         forn(j, dim)
        //             cin >>
        //     A[i][j];
        // cin >> n;
        // powerOfMatrix(A, dim, n);
        // printMatrix(A, dim);

        // primeFactorisation(n);
        // cin >> a >> b;
        // cout << primes[l] << endl;
        // cout << isPrime(n) << endl;
        // cout << power1(a, b) << endl;
        // cout << power2(a, b) << endl;
        // cout << gcd(a, b) << endl;
        // cout << powerModulo(a, b, 7) << endl;
    }
    return 0;
}
//erverything is tested //once read comment if any ...
