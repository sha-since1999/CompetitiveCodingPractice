#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sahu()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
}

int main()
{
    sahu();
    int noOfcars, collision = 0;
    cin >> noOfcars;
    map<int, int> map;
    ll x, y, speed, distance;
    while (noOfcars--)
    {
        cin >> x >> y >> speed;
        distance = sqrt(abs(x * x) + abs(y * y));
        ll time = (ll)(distance / speed);
        map[time] += 1;
    }
    int n;
    for (auto &&i : map)
    {
        n = i.second;
        if (n > 1)
            collision += (n * (n - 1)) / 2;
    }

    cout << collision << endl;
    return 0;
}

//test case
// 5
// 5 12 1
// 16 63 5
// -10 24 2
// 7 24 2
// -24 7 2