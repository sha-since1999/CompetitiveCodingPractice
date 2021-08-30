#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    int n, sum = 0;
    while (cin >> n)
    {
        sum += n;
    }
    cout << sum << endl;


// another way to do this 
    // vector<int> v;
    // do
    // {
    //     int x;
    //     cin >> x;
    //     v.push_back(x);
    // } while (cin.get() != '\n');

    // for (int x : v)
    // {
    //     cout << x << " ";
    // }
    // cout << "size :" << v.size() << endl;
    
    return 0;
}