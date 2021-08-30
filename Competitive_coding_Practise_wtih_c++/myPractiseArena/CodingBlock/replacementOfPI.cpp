#include <bits/stdc++.h>
#include "input.h"
using namespace std;
string replacePI(string s) //method1
{
    if (s.size() == 1)
        return s;

    if (s.substr(0, 2) == "pi")
    {
        if (s.size() == 2)
            return "3.14";
        return "3.14" + replacePI(s.substr(2));
    }
    return s.substr(0, 1) + replacePI(s.substr(1));
}

string replacePI2(string s) //method2
{
    if (s.find("pi") != string::npos)
    {
        int idx = s.find("pi");
        s.replace(idx, 2, "3.14");
        return replacePI2(s);
    }
    return s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    // cout << replacePI(s) << endl;

    cout << replacePI2(s) << endl;

    return 0;
}

// input: xpiasdpidehdappii
// output: x3 .14asd3.14dehdap3.14i
