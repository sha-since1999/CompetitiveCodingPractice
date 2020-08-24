#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int par[100010];
int find(int a) // iterative find
{
    vector<int> v;
    while (par[a] > 0)
    {
        v.push_back(a);
        a = par[a];
    }
    for (int i : v)
        par[i] = a;
    return a;
}

int rfind(int a) // recursive find
{
    if (par[a] < 0)
        return a;
    return par[a] = find(par[a]);
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    par[a] += par[b];
    par[b] = a;
}
int main()
{
    int n, m;
    cin >> n >> m;
    memset(par, -1, sizeof(par));

    for (int i = 0; i < m; i++)
    {

        int a, b;
        cin >> a >> b;
        a = find(a);
        b = find(b);
        if (a != b)
            merge(a, b);
    }
    int res = 1;
    for (int i = 1; i <= n; i++)
        if (par[i] < 0)
            res = (res * abs(par[i])) % mod;

    cout << res % mod << endl;

    return 0;
}
