#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    bool flag = true;
    int pp = 1;
    vector<int> v[n];
    for (int i = 0; i < n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            v[i].push_back(pp++);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i%2==0)
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                cout << v[i][n - j-1] << " ";
            }
        }
        cout << endl;
    }
}
// 1	2	3	4  
// 8	7	6	5  
// 9	10	11	12 
// 16	15	14	13 
