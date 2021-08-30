#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char ch[1000];
    cin.getline(ch, 1000);
    int n = strlen(ch);
    // string s;
    // getline(cin, s);
    // int n s.size();


    if (n == 1 or n == 0)
    {
        cout << ch << endl;
        return 0;
    }
    int p_i = 0;
    for (int c_i = 0; ch[c_i]; c_i++)
    {
        if (ch[c_i] != ch[p_i])
            ch[++p_i] = ch[c_i];
    }
    ch[++p_i] = '\0';
    cout << ch << endl;
    return 0;
}