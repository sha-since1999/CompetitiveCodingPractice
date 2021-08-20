#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    string s, aim;
    cin >> s;
    cin >> aim;
    int i = 0, ans = 0;
    while (i < s.size() - 3)
    {
        if (aim == s.substr(i, 3))
            ans++;
        // i += aim.size();
        i++;
    }
    cout << ans << endl;
    return 0;
}