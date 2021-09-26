#include <bits/stdc++.h>
using namespace std;

int main()
{

    set<int> st{1, 2, 3, 5, 7, 24};

    cout << *lower_bound(st.begin(), st.end(), 4) << endl;
    cout << *st.lower_bound(4) << endl;
    if (st.find(4) == st.end())
        cout << "NOT found" << endl;
    else
        cout << *st.find(4) << endl;

    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
        cout << *it << endl;

    for (int x : st)
    {
        cout << x << " ";
    }

    set<pair<int, int>> stt{{2, 3}, {3, 4}};
    stt.insert(make_pair(5, 3));
    stt.insert({6, 7});
    stt.erase(make_pair(0, 4));           // nothing will happen when not find that pair
    stt.erase(stt.find(make_pair(3, 4))); // this can give RTE when not find
    for (auto p : stt)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}