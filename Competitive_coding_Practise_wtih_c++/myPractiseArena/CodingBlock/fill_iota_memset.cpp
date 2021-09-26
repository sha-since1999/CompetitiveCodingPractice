#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[10];
    vector<int> v{1, 2, 3, 5, 7, 24};
    v.erase(v.begin() + 2);
    // iota(v.begin(), v.end(), 5);  // 5 6 7 8 9 10
    // fill(v.begin(), v.end(),5);   //  5 5 5 5 5 5
    // memset(a, -1, sizeof(a));    //  -1 -1 -1 -1 -1   only for 0/-1
    // for (int x : a)
    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}