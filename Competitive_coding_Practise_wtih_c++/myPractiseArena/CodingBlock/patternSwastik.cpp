#include <bits/stdc++.h>

using namespace std;
int n;
bool check(int i, int j)
{
    if (i == (n + 1) / 2)
        return true;
    if (j == (n + 1) / 2)
        return true;
    if (j == 1 and i <= n / 2)
        return true;
    if (i == n and j <= n / 2)
        return true;
    if (i == 1 and j > n / 2)
        return true;
    if (j == n and i > n / 2)
        return true;

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    n = !(n & 1) ? n + 1 : n; // just before better printing .

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (check(i, j))
            {
                cout << " * ";
            }
            else
                cout << "   ";
        }
        cout << endl;
    }
    return 0;
}