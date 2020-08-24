#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int par[100010];
int R[100010];
vector<int> edage;

int find(int a)
{
    if (par[a] < 0)
        return a;
    return par[a] = find(par[a]);
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    par[a] = min(par[a], par[b]);
    par[b] = a;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < 100010; i++)
        par[i] = -i;

    for (int i = 0; i < m; i++)
    {

        int a, b;
        cin >> a >> b;
        a = find(a);
        b = find(b);
        if (a != b)
            merge(a, b);
    }
    int q;
    cin >> q;

    for (int i = 1; i <= q; i++)
    {
        int a, b, x, y;
        cin >> x >> y;
        a = find(x);
        b = find(y);
        if (a == b)
            cout << "TIE" << endl;
        else if (abs(par[a]) > abs(par[b]))
            cout << x << endl;
        else
            cout << y << endl;
    }

    return 0;
}
