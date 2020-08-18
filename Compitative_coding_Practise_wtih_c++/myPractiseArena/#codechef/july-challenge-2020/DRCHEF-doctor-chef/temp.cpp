#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, day_count = 0;
        cin >> n >> x;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        ll lb = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
        for (int i = lb; i < n; i++)
        {
            if (x < vec[i])
            {
                while (x < vec[i])
                {
                    x = 2 * x;
                    day_count++;
                }
                day_count++;
            }
            else
                day_count++;
            x = 2 * vec[i];
        }
        ll total_count = lb + day_count;
        if (lb != 0)
        {
            day_count = 0;
            lb--;
            for (int i = lb; i < n; i++)
            {
                if (x < vec[i])
                {
                    while (x < vec[i])
                    {
                        x = 2 * x;
                        day_count++;
                    }
                    day_count++;
                }
                else
                    day_count++;
                x = 2 * vec[i];
            }
            if (day_count + lb < total_count)
                cout << day_count + lb << endl;
            else
                cout << total_count << endl;
        }
        else
            cout << total_count << endl;
    }
    return 0;
}