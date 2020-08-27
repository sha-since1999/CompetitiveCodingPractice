#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define N 101
typedef unsigned long long ull;
ull A[N][N], I[N][N];
void multiplicaton(ull a[][N], ull b[][N], ull n)
{
    ull c[n][n];
    forn(i, n)
        forn(j, n)
    {
        c[i][j] = 0;
        forn(k, n) c[i][j] += a[i][k] * b[k][j];
    }
    forn(i, n)
        forn(j, n)
            a[i][j] = c[i][j];
    return;
}

void powerOfMatrix(ull a[][N], ull dim, ull n)
{
    forn(i, dim)
        forn(j, dim)
    {
        if (i == j)
            I[i][j] = 1;
        else
            I[i][j] = 0;
    }
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

void findNthElement(ull f1, ull f2, ull n) //find n th fibonacci element
{
    ull a[N][N] = {{0, 1}, {1, 1}};
    ull f[N][N] = {{f1, f2}, {1, 1}};
    powerOfMatrix(a, 2, n - 1);
    multiplicaton(f, a, 2);
    cout << f[0][0] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ull t;
    cin >> t;
    while (t--)
    {
        ull f1, f2, n;
        cin >> f1 >> f2 >> n;
        findNthElement(f1, f2, n);
    }

    return 0;
}