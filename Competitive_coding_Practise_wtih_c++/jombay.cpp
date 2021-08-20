#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    string str;
    int h[s.size()] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c != ' ')
            str.push_back(c);
    }

    for (int i = 
    0; i < str.size(); i++)
    {
        if (s[i] == 'G')
            h[i]++;
    }
    int ans = 0;
    cout << str << endl;
    for (bool i : h)
        cout << i;
    for (int i = 0; i < str.size(); i++)
    {
        if (s[i] == 'P')
            for (int j = i + n + 1; j >= i; j--)
            {
                if (h[j] == true)
                {
                    h[j]--;
                    ans++;
                    break;
                }
            }
    }

    cout << ans << endl;
    return 0;
}