
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
// #include "sahu.h"
// #include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int T;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;

    while (T--)
    {
        bool flag = 0;
        int N, temp;
        vector<ll> A;
        vector<ll> B;
        cin >> N;
        ll total_cost = 0;
        int mn = 1000000000;
        unordered_map<int, int> mp;
        vector<int> v1;
        vector<int> v2;
        for (ll i = 0; i < N; i++)
        {
            cin >> temp;
            A.push_back(temp);
            mp[temp]++;
            mn = min(mn, temp);
        }
        for (ll j = 0; j < N; j++)
        {
            cin >> temp;
            B.push_back(temp);
            mp[temp]++;
            mn = min(mn, temp);
        }
        for (auto m : mp)
            if ((m.second % 2) != 0)
                flag = 1;
            else
                mp[m.first] /= 2;

        if (!flag)
        {
            sort(A.begin(), A.end());
            sort(B.begin(), B.end());
            for (int i = 0; i < N; i++)
            {
                if (A[i] != B[i]&&)
                {
                    v1.push_back(A[i]);
                    v2.push_back(B[i]);
                    i++;
                }
                
            }
            sort(v1.begin(), v1.end(), greater<int>());
            sort(v2.begin(), v2.end(), greater<int>());
            if (v1.size() != v2.size())
                flag = 1;
            for (ll i = 0; i < v1.size(); i++)
                total_cost += min((2 * mn), (min(v1[i], v2[i])));
            if (v1.size() == 0 || v2.size() == 0)
                total_cost = 0;
        }
        flag ? cout << -1 << endl : cout << total_cost << endl;
    }
    return 0;
}