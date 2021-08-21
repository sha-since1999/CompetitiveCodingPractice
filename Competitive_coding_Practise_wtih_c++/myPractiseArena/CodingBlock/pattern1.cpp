#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x = 1;
    int n = 5;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << x << " ";
            // x = x ?0:1;
            x ^= 1;
        }
        cout << endl;
    }

    return 0;
}