#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end(), greater<int>());
        int q;
        cin >> q;
        for (int j = 0; j < q; j++)
        {
            long long int x, y;
            cin >> x >> y;
            int i = 0;
            int wall = n;
            while (i < n)
            {
                long long int check = x + y - a[i++];
                if (check == 0)
                {
                    wall = -1;
                    break;
                }
                if (check < 0)
                    wall--;
                else
                    break;
            }
            cout << wall << endl;
        }
    }

    return 0;
}