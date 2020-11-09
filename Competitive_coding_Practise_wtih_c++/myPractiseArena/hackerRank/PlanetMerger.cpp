#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int par[100010];
int find(int a) // recursive find
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
    int res = n;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a = find(a);
        b = find(b);
        if (a != b)
        {
            merge(a, b);
            res--;
        }
        cout << res << endl;


    }
    return 0;
}
