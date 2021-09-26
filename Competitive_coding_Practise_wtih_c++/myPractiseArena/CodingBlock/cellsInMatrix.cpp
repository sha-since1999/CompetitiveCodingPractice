#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    set<int> si, sj;
    for (int i = 1; i <= n; i++)
    {
        si.insert(i);
        sj.insert(i);
    }

    while (k--)
    {
        int x, y;
        cin >> x >> y;
        si.erase(x);
        sj.erase(y);
        cout << si.size() * sj.size() << " ";
    }

    return 0;
}