#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {-1, 2, 4, -3, 5, 2, -5, 2};

    int sum = 0;
    int max_sum = INT32_MIN;
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        sum = max(sum + a[i], a[i]);
        max_sum = max(sum, max_sum);
    }

    cout << max_sum << endl;

    return 0;
}