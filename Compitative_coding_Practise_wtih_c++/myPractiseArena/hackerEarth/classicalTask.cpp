#include <bits/stdc++.h>
using namespace std;
int par[500010];
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
    par[a] += par[b];
    par[b] = a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    memset(par, -1, sizeof(par));
    for (int i = 0; i < m; i++)
    {
        int a, b, x, y, cmp;
        cin >> a >> b;
        cmp = a;
        x = find(a);
        y = find(b);

        if (x != y)
            merge(x, y);
        // cout << a << " " << b << endl;
        while (cmp != b)
        {
            a++, b--;
            // cout << a << " " << b << endl;
            x = find(a);
            y = find(b);
            if (x != y)
                merge(x, y);
        }
    }
    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << par[i] << " ";
        if (par[i] < 0)
            cc++;
    }
    cout << cc << endl;

    return 0;
}
