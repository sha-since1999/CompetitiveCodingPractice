#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    char s[1000];
    char largest[1000];
    cin.get(); // this to ignore extra character ie. '\n' after input of n
    for (int i = 0; i < n; i++)
    {
        cin.getline(s, 1000);
        // cout << s << endl;
        if (strlen(largest) < strlen(s))
        {
            strcpy(largest, s);
        }
    }
    cout << largest << endl;
    cout << strlen(largest) << endl;
    return 0;
}