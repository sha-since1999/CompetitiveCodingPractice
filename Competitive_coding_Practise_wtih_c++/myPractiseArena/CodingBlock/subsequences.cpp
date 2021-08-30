#include <bits/stdc++.h>
#include "input.h"
using namespace std;
void printPowerSet(string s)
{
    int n = 1 << s.size();
    cout << "{ ";
    for (int i = 1; i < n; i++)
    {
        int tmp = i;
        int j = 0;
        while (tmp > 0)
        {
            if (tmp & 1)
                cout << s[j];
            tmp >>= 1;
            j++;
        }
        cout << ", ";
    }
    cout << " }" << endl;
}
void printSubsequences(string s, string out)
{
    if (s.empty())
    {
        cout << out << " ";
        return;
    }
    char ch = s[0];
    printSubsequences(s.substr(1), out);
    printSubsequences(s.substr(1), out + ch);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "abc";

    printPowerSet(s);
    printSubsequences(s, "");

    return 0;
}