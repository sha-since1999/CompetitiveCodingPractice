#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> powerSet(vector<int> a)
{
    vector<vector<int>> powerset(1);
    for (int ele : a)
    {
        vector<int> currSubset;
        int len = powerset.size();
        for (int i = 0; i < len; i++)
        {
            currSubset = powerset[i];
            currSubset.push_back(ele);
            powerset.push_back(currSubset);
        }
    }
    return powerset;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a{1, 2, 3};
    vector<vector<int>> powerset;
    powerset = powerSet(a);
    for (auto v : powerset)
    {
        cout << "[ ";
        for (int x : v)
            cout << x << " ";

        cout << "]";
    }

    return 0;
}
