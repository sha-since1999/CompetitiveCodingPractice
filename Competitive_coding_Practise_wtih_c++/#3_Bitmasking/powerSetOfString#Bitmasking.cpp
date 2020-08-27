#include <bits/stdc++.h>
using namespace std;
void powerSetString(string s)
{
    int x = 1 << s.size();
    cout << "[ \" \" ,";
    for (int i = 1; i < x - 1; i++)
    {
        int temp = i;
        int idx = 0;
        while (temp)
        {
            if (temp & 1)
                cout << s[idx];
            idx++;
            temp >>= 1;
        }
        cout << ", ";
    }
    cout << s << " ]" << endl;
}

vector<vector<int>> powerSetDigit(vector<int> a)
{
    vector<vector<int>> powerset;
    int x = 1 << a.size();
    powerset.clear();
    for (int i = 0; i < x; i++)
    {
        int temp = i;
        int idx = 0;
        vector<int> currSubset;
        while (temp)
        {
            if (temp & 1)
                currSubset.push_back(a[idx]);
            idx++;
            temp >>= 1;
        }
        powerset.push_back(currSubset);
    }
    return powerset;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "abc";
    powerSetString(s);

    vector<int> a{1, 2, 3};
    vector<vector<int>> powerset;
    powerset = powerSetDigit(a);
    for (auto v : powerset)
    {
        cout << "[ ";
        for (int x : v)
            cout << x << " ";

        cout << "]";
    }

    return 0;
}
