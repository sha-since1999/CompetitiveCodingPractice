#include <bits/stdc++.h>
using namespace std;
void swap(char &a, char &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "rohitsahu";
    int i;
    for (i = 0; s[i]; i++);
    
    int h = i-1;
    int l = 0;

    while (l < h) swap(s[l++], s[h--]);
    
    cout << s << endl;
    return 0;
}