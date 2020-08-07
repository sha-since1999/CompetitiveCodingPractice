#include <bits/stdc++.h>
using namespace std;
void sahu()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
}
int main()
{
    sahu();
    string exp;
    getline(cin, exp);
    stack<int> stk;
    // cout << exp << endl;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == 40 || exp[i] == 91 || exp[i] == 123)
            stk.push(exp[i]);
        if (exp[i] == 41 || exp[i] == 93 || exp[i] == 125)
        {
            if (stk.empty())
            {
                cout << "paranthesis arr not baanced" << endl;
                return 0;
            }
            stk.pop();
        }
    }
        if (!stk.empty())
        {
            cout << "paranthesis arr not baanced" << endl;
            return 0;
        }
    cout << "paranthsis ara balanced" << endl;
    return 0;
}