#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
// #include <bits/stdc++.h>
#include <map>
using namespace std;
typedef long long int ll;
ll N;
void third_points(vector<pair<ll, ll>> points)
{
    map<ll, int> hash_of_fisrst_cord;
    map<ll, int> hash_of_sec_cord;
    for (auto i : points)
    {
        hash_of_fisrst_cord[i.first]++;
        hash_of_sec_cord[i.second]++;
    }

    for (auto i : hash_of_fisrst_cord)
    {
        if ((i.second & 1) == 1)
        {
            cout << i.first << " ";
            break;
        }
    }
    for (auto j : hash_of_sec_cord)
    {
        if ((j.second & 1) == 1)
        {
            cout << j.first << endl;
            break;
        }
    }
}

    ll T;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
    {

        cin >> N;
        N = 4 * N - 1;
        vector<pair<ll, ll>> points;
        for (ll i = 0; i < N; i++)
        {
            ll x = 0, y = 0;
            cin >> x >> y;
            points.emplace_back(x, y);
        }
        third_points(points);
    }
}
