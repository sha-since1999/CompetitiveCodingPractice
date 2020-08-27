#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void sahu()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
}

int main()
{
    sahu();
    int n;
    cin >> n;
    int q;
    cin >> q;
    int col;
    int data;
    vector<vector<int>> vec(100000);
    for (int i = 0; i < n; i++)
    {
        cin >> col;
        for (int j = 0; j < col; j++)
        {
            cin >> data;
            vec[i].push_back(data);
        }
    }
    int p, s;
    while (q--)
    {
        cin >> p >> s;
        cout << vec[p][s] << endl;
    }
    return 0;
}

//output formate for this

// 2 2
// 3 1 5 4
// 5 1 2 8 9 3
// 0 1
// 1 3