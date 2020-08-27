#include <bits/stdc++.h>
#include "sahu.h"
using namespace std;
int bitscore(int n)
{
    int mn = INT32_MAX;
    int mx = INT32_MIN;
    while (n)
    {
        int d = n % 10;
        n = n / 10;
        mn = min(mn, d);
        mx = max(mx, d);
    }
    return (mx * 11 + mn * 7) % 100;
}

int main()
{

    int N;
    cin >> N;
    int cnt;
    vector<int> v, odd_pos_bitscore, even_pos_bitscore, paircnt(10, 0);

    for (int i = 1; i < N + 1; i++)
    {
        int x;
        cin >> x;
        if (i & 1)
            odd_pos_bitscore.push_back(bitscore(x));
        else
            even_pos_bitscore.push_back(bitscore(x));
    }
    for (int i : odd_pos_bitscore)
        paircnt[i > 10 ? i / 10 : i]++;
    for (int i : even_pos_bitscore)
        paircnt[i > 10 ? i / 10 : i]++;
    for (int p : paircnt)
    {
        if (p == 2)
            cnt++;
        if (p > 2)
            cnt += 2;
    }
    cout << cnt << endl;

    return 0;
}
// 8
// 234 567 321 345 123 110 767 111
////////////