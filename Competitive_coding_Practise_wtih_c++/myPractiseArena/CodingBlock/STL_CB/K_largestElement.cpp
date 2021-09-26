#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;

    int k;
    cin >> k;
    int x;
    cin.get();
    while (cin.get() != '\n')
    {
        cin >> x;
        if (pq.size() < k)
            pq.push(x);
        else if (pq.top() < x)
        {
            pq.pop();
            pq.push(x);
        }
    }
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}