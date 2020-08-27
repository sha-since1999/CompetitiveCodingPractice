#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void sahu()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
}
int main()
{
    sahu();
    int q;
    cin >> q;
    set<int> s;
    while (q--)
    {
        int y, x;
        cin >> y >> x;
        if (y == 1)
            s.insert(x);
        else if (y == 2)
            s.erase(x);
        else
        {
            auto f = s.find(x);
            if (f != s.end())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    // for (auto &&i : s)
    //   cout << i << endl;
    return 0;
}
