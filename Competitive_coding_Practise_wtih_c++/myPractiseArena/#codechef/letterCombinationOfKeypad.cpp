#include <bits/stdc++.h>
using namespace std;

vector<string> letterCombination(int *a, int n)
{

    string table[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> res;

    queue<string> q;
    q.push("");
    while (!q.empty())
    {
        string s = q.front();
        q.pop();
        if (s.size() == n)
        {
            res.push_back(s);
            // cout << s << " ";
        }
        else
            for (char c : table[a[s.size()]])
            {
                q.push(s + c);
            }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 2;
    // cin >> n;
    int a[n] = {2, 3};
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }

    vector<string> s = letterCombination(a, n);
    for (string r : s)
    {
        cout << r << " ";
    }
    return 0;
}