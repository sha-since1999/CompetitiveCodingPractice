#include <bits/stdc++.h>
// #include "input.h"
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() and dq.front() < i - k)
            dq.pop_front();
        while (!dq.empty() and a[dq.back()] < a[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            cout << a[dq.front()] << " ";
    }
    return 0;
}