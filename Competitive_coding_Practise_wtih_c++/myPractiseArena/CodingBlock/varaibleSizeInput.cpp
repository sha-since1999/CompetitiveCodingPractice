#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> v;
    do
    {
        int x;
        cin >> x;
        v.push_back(x);
    } while (cin.get() != '\n');

    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "size :" << v.size() << endl;
    return 0;
}