#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int n1 = 0;
    int n2 = 1;
    cout << n1 << " " << n2 << " ";
    for (int i = 0; i < n; i++)
    {
        int n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        cout << n3 << " ";
    }

    return 0;
}