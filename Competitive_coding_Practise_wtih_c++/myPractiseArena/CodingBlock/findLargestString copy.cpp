#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    char s[1000];
    char largest[1000];
    for (int i = 0; i < n; i++)
    {
        cin.getline(s, 1000);
        if (strlen(largest) > strlen(s))
        {
            largest = s;
        }
    }
    cout << largest << endl;
    cout << strlen(largest) << endl;
    return 0;
}