#include <bits/stdc++.h>
using namespace std;
bool cmppair(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}
bool cmp(int a, int b) { return a > b; }
int main()
{

    multimap<int, int, greater<int>> mp = {{3, 4}, {3, 2}, {7, 5}};
    vector<int> v = {3, 5, 6, 7, 88, 2, 5, 66};
    vector<pair<int, int>> vp = {{3, 4}, {5, 2}, {7, 5}};

    // sort(v.begin(), v.end(), greater<int>());
    sort(v.begin(), v.end(), cmp);

    cout << "\nsorted vector output here" << endl;
    for (int i : v)
        cout << i << " ";

    cout << "\nsorted pair of vactor here" << endl;
    sort(vp.begin(), vp.end(), cmppair);
    for (auto i : vp)
        cout << i.first << " " << i.second << endl;

    cout << "\nsorted multimap here" << endl;
    for (auto m : mp)
        cout << m.first << " " << m.second << endl;

    return 0;
}
