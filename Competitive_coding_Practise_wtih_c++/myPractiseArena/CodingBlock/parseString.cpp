#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "1C1B1B0A0";
    cin >> s;
    int ans = s[0] - '0';
    for (int i = 0; s[i + 1]; i++)
    {
        if (s[i] >= 65)
            if (s[i] == 'A')
                ans &= (s[i + 1] - '0');
        if (s[i] == 'B')
            ans |= (s[i + 1] - '0');
        if (s[i] == 'C')
            ans ^= (s[i + 1] - '0');
    }
    cout << ans << endl;
    return 0;
}