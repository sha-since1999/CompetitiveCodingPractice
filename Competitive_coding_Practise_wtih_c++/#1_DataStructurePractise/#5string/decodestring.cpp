#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char s[] = "u39[b]fg3[sd2[gr]ax3[a2[t]p]]sl";
    vector<int> v;
    stack<char> st;
    int n = 0;
    for (int i = 0; i < s[i]; i++)
    {
        if (s[i] >= '0' and s[i] <= '9')
        {
            n = n * 10 + (s[i] - '0');
            if (!(s[i + 1] >= '0' and s[i + 1] <= '9'))
            {
                v.push_back(n);
                n = 0;
            }
            continue;
        }
        if (s[i] == ']')
        {
            string str1, str2;
            while (st.top() != '[')
            {
                str1.push_back(st.top());
                st.pop();
            }
            st.pop();
            int m = v.back();
            v.pop_back();
            // cout << m << endl;
            st.pop();

            while (m--)
                str2 += str1;
            for (char c : str2)
                st.push(c);
        }
        else
            st.push(s[i]);
    }
    string res;
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}