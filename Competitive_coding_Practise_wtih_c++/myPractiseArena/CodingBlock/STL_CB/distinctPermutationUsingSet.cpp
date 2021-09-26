#include <bits/stdc++.h>
using namespace std;
void permute(string s, int k, set<string> &st)
{
    if (!s[k])
        st.insert(s);
    else
        for (int i = k; s[i]; i++)
        {
            swap(s[i], s[k]);
            permute(s, k + 1, st);
            swap(s[i], s[k]);
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<string> st;
    permute("aba", 0, st);
    for (string s : st)
        cout << s << endl;

    return 0;
}