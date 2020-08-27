
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
    int tv_room = 1500;
    int no_of_room;
    int non_tv_room;
    ll cost = 0;
    ll revenue;
    cin >> no_of_room;
    cin >> tv_room >> non_tv_room;
    cin >> revenue;

    vector<int> year_analysis;

    int estimate;
    vector<int> v = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= v[i]; j++)
        {
            estimate = pow(abs(6 - i), 2) + abs(j - 15);
            year_analysis.push_back(estimate);
        }
    }
    // ll sum = 0;
    // for (auto &&i : year_analysis)
    // {
    //     sum += i;
    // }
    // cout << sum / 365 << endl;

    for (int i = 1; i <= no_of_room; i++)
    {
        cost = 0;
        for (auto &&k : year_analysis)
        {
            if (k >= no_of_room)
            {
                cost = cost + (tv_room * i + (no_of_room - i) * non_tv_room);
            }
            else
            {
                if (k - i > 0)
                    cost += non_tv_room * (k-i);
                else
                    cost += (tv_room * i + abs(k - i) * non_tv_room);
            }
        }
        cout << cost << endl;
        if (cost >= revenue)
        {
            cout << i << endl;
            cout << "end" << endl;
            break;
        }
    }

    return 0;
}