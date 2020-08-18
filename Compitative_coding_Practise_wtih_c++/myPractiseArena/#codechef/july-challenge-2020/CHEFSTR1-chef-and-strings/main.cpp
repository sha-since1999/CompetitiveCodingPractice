#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll sum = 0;
ll T;
ll N;
ll x;
ll check_sum = 0;
int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        N = 0;
        x = 0;
        cin >> N;
        vector<int> vec;
        for (ll i = 0; i < N; i++)
        {
            cin >> x;
            vec.push_back(x);
        }
        sum = 0;
        check_sum = 0;
        for (int j = 0; j < N - 1; j++)
        {
            if (vec[j] < 0 && vec[j + 1] < 0)
                check_sum = abs(vec[j + 1]) - abs(vec[j]) - 1;
            else
                check_sum = abs(vec[j + 1] - vec[j]) - 1;
            if (check_sum > 0)
                sum += check_sum;
        }
        cout << sum << endl;
    }
    return 0;
}