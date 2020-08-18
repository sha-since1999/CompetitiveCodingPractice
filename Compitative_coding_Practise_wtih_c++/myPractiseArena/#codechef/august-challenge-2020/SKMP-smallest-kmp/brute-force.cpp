// #include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<stdlib.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        string s, p;
        cin>>s>>p;
        multiset<string> set;
        for (char c: s)
            set.insert(string(1, c));
        for (char c: p)
            set.erase(find(set.begin(), set.end(), string(1, c)));
        set.insert(p);
        for (string c:set)
            cout<<c;
        cout<<endl;
    }
    return 0;
}