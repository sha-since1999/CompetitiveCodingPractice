#include <iostream>
// #include "sahu.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> data;
int P, D;
int bc = pow(2, P);
// int solve(int i)
// {
//     if (i > D && i != P)
//         return INT_MAX;
//     int sum = 0, temp;
//     for (int k = i; k < P; k++)
//     {
//         int mn = INT_MAX;
//         for (int j = 0; j < D; j++)
//         {
//             for (int l = 0; l < k; k++)
//             {
//                 sum += data[j][l];
//             }
//             mn = min(mn, sum);
//         }
//         temp = min(solve(k), mn);
//     }
//     return temp;
// }

int solve(int i, unsigned int ck)
{
    int ans = 0;
    if (ck == bc)
    {
        cout << __builtin_popcount(ck) << endl;
        return 123;
    }
    int mn = INT32_MAX;
    for (int k = i; k <= P; k++)
    {
        int x = 1;
        unsigned int nk;
        x = x << k;
        nk = ck | x;
        int temp = INT32_MAX;
        for (int d = 0; d < D; d++)
        {
            // cout << data[d][k - 1] << " ";
            ans = solve(k + 1, nk) + data[d][k - 1];
            temp = min(temp, ans);
        }
        mn = min(mn, temp);
    }
    return mn;
}

int main()
{
    int x;
    cin >> D >> P;
    for (int i = 0; i < D; i++)
    {
        vector<int> p_list;
        for (int j = 0; j < P; j++)
        {
            cin >> x;
            p_list.push_back(x);
        }
        data.push_back(p_list);
    }
    cout << solve(1, 0) << endl;
    return 0;
}

// test case

// 2 4
// 2 2 2 2
// 3 1 2 3