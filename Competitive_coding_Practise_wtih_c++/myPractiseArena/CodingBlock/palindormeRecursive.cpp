#include <bits/stdc++.h>
#include "input.h"
using namespace std;
bool isPalindrome(string s, int i, int j)
{
    if (j - i < 1)
        return true;
    if (s[i] == s[j])
        return isPalindrome(s, i + 1, j - 1);
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "absba";
    cout << isPalindrome(s, 0, s.size() - 1);

    return 0;
}