#include <bits/stdc++.h>

using namespace std;

vector<int> extractIntfromString(string s)
{
    vector<int> v;
    int x = 0;

    for (int i = 0; s[i]; i++)
    {
        if (s[i] == ' ')
            v.push_back(x),x = 0;
        else
            x = (s[i] - '0') + x * 10;
    }
    v.push_back(x);
    return v;
}

void readline(char a[], int n, char delim = '\n')
{
    char x = cin.get();
    int i = 0;
    while (x != delim)
    {
        a[i++] = x;
        x = cin.get();
    }
    a[i] = '\0';
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char s[1000];
    // cin.getline(a, 1000);
    readline(s, 1000);

    vector<int> a = extractIntfromString(s);
    for (int i : a)
        cout << i << endl;

    return 0;
}