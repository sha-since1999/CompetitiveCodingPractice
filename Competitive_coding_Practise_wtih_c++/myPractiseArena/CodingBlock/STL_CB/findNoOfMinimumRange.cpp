#include <bits/stdc++.h>
using namespace std;
int a[] = {-1, 2, 1, 1, 5, 3, 6, 7, 3, 4};
int b[] = {1, 2, 3, 2, 6, 7, 8, 9, 5, 8};
int n = sizeof(a) / sizeof(a[0]);
bool comparator(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
int findRange(int x, int ans)
{
    pair<int, int> mp[n];
    for (int i = 0; i < n; i++)
    {
        mp[i] = make_pair(b[i], a[i]);
    }
    sort(mp, mp + n, comparator);
    for (auto m : mp)
        cout << m.first << " " << m.second << endl;
    int tmp = INT32_MAX;
    while (tmp > 1)
    {
        for (auto m : mp)
        {
            if (m.first >= x)
            {
                tmp = min(tmp, m.second);
            }
            else
                break;
        }
        x = tmp;
        ans++;
    }
    return ans;
}
int main()
{
    cout << findRange(8, 0) << endl;
    return 0;
}