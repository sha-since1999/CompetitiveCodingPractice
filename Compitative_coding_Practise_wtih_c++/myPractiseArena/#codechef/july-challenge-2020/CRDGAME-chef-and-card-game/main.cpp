// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long int ll;
ll sumOfDigit(ll n)
{
    ll sum = 0;
    while (n)
    {
        int x = n % 10;
        sum += x;
        n = floor(n / 10);
    }
    return sum;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll N, x = 0, y = 0;
        ll chef = 0;
        ll morty = 0;
        cin >> N;
        vector<pair<ll, ll>> card;
        for (ll i = 0; i < N; i++)
        {
            cin >> x >> y;
            card.emplace_back(x, y);
        }
        for (auto i : card)
        {
            x = sumOfDigit(i.first);
            y = sumOfDigit(i.second);
            if (x > y)
                chef++;
            else if (y > x)
                morty++;
            else
            {
                chef++;
                morty++;
            }
        }
        if (chef > morty)
            cout << 0 << " " << chef << endl;
        else if (morty > chef)
            cout << 1 << " " << morty << endl;
        else
            cout << 2 << " " << chef << endl;
    }
    return 0;
}