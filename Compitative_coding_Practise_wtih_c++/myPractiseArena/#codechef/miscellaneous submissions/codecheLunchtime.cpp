#include <bits/stdc++.h>
#include "sahu.h"
using namespace std;
typedef long long ll;
ll N, T, K, x, sum = 0;
int main()
{
    cin >> T;
    while (T--)
    {
        int index = 0;
        int max = INT16_MIN;
        vector<ll> v;
        v.push_back(-1);
        cin >>
            N >> K;
        for (int i = 1; i <= N; i++)
        {
            cin >> x;
            v.push_back(x);
            if (x > max)
                max = x;
        }
        int no_of_bits = (int)log2(max) + 1;
        int limit = pow(2, no_of_bits - 1);
        max = INT_MIN;
        for (int i = 1; i <= limit; i *= 2)
        {
            for (int j = 1; j <= N; j++)
            {

                sum += (i & v[j]);
            }
            if (sum > max)
            {
                index = i;
                max = sum;
            }
        }
        cout << index << endl;
    }
    return 0;
}