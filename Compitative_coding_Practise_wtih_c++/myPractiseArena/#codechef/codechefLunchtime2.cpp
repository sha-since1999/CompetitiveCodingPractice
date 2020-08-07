#include <bits/stdc++.h>
#include "sahu.h"
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin >> T;
    int x;
    while (T--)
    {
        ll N;
        cin >> N;
        vector<int> v;
        vector<int> vf;
        map<int, int> map;
        int max = INT16_MIN;
        string s = "YES";
        for (int i = 0; i < N; i++)
        {
            cin >> x;
            map[x]++;
            if (x > max)
                max = x;
        }

        if (map[max] > 1)
            s = "NO";
        x = -1;
        for (auto &&i : map)
        {
            x = i.first;
            // cout << i.first << "  " << i.second << endl;
            if (i.second > 2)
            {
                s = "NO";
                break;
            }

            if (i.second == 2)
            {
                v.push_back(x);
                vf.push_back(x);
            }
            else
                v.push_back(x);
        }
        // cout<<s<<endl;
        if (s == "YES")
        {
            // cout << s <<" "<< v.size()<< endl;
            cout << s << endl;
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
            for (int i = (vf.size() - 1); i >= 0; i--)
                cout << vf[i] << " ";
            cout << endl;
        }
        else
            cout << s << endl;
    }
    return 0;
}