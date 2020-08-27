#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
// #include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll T;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        ll N, temp, x;
        cin >> N >> x;
        vector<ll> vec;
        for (ll i = 0; i < N; i++)
        {
            cin >> temp;
            vec.push_back(temp);
        }
        ll day_count = 0;
        sort(vec.begin(), vec.end());
        ll i = upper_bound(vec.begin(), vec.end(), x) - vec.begin();
        // for(int k:vec)
        //     cout << k << " ";
        i = i - 1;
        N if (i < 0)
            i = 0;
        if (i > vec.size() - 1)
            return vec.size();
        if (vec[i] < x / 2)
        {
            i++;
        }
        // cout << i;
        day_count = i;
        for (ll j = i; j < vec.size(); j++)
        {
            ll
                rest_of_infected_people = vec[j];
            ll fixed_population = vec[j];
            while (rest_of_infected_people > 0)
            {
                vec[j] = vec[j] - x;
                if (rest_of_infected_people <= x)
                {
                    x += rest_of_infected_people, day_count++;
                    break;
                }
                else
                    x = 2 * x;
                if (vec[j] <= 0)
                {
                    day_count++;
                    break;
                }
                if (fixed_population < (2 * vec[j]))
                    vec[j] = fixed_population;
                else
                    vec[j] = 2 * vec[j];

                rest_of_infected_people = vec[j];
                day_count++;
                // cout << vec[j] << " ";
                // cout << "day" << day_count;
                // cout << "x  :" << x << endl;
            }

            if (x > (2 * fixed_population))
                x = 2 * fixed_population;
        }

        cout << day_count << endl;
    }
    return 0;
} //not working compwletely 20 points