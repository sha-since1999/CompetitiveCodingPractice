#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //  for string --------
    string s = "abc";
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    // for vector......---------

    vector<int> v = {1, 2, 3};
    do
    {
        for (int x : v)
            cout << x;
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    //    for array .........--------
    int a[3] = {5, 6, 7};
    do
    {
        for (int x : a)
            cout << x;
        cout << endl;
    } while (next_permutation(a, a + 3));

    return 0;
}
