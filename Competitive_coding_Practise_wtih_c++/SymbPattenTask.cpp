#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 0;
    cout << " Enter the value of N" cin >> n;
    int i, cin >> i;
    for (i = 0; i < n; i++)
    {
        for (int j = -6; j < n - i; j++)
            cout << " ";
        for (int j = 0; j < i; j++)
            cout << "* ";
        cout << endl;
    }
    for (; i > 0; i--)
    {
        for (int j = -6; j < n - i; j++)
            cout << " ";
        for (int j = 0; j < i; j++)
            cout << "* ";
        cout << endl;
    }
    cout << endl;
    return 0;
}

