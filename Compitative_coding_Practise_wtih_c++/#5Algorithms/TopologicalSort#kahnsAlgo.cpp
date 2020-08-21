#include <bits/stdc++.h>
using namespace std;
vector<int> ar[10001];
int in[10001];
vector<int> res;
void kahnAlgo(int n)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for (int child : ar[curr])
        {
            in[child]--;
            if (in[child] == 0)
                q.push(child);
        }
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        in[b]++;
    }
    kahnAlgo(v);
    cout << " topoLogical: ";
    for (int i : res)
        cout << i << " ";

    return 0;
}
// note here : if size of res is not equal to N its mean there is cycle in the graph;

// test case
// 9 9
// 1 2
// 2 9
// 2 5
// 2 6
// 4 8
// 3 4
// 5 9
// 1 8
// 5 7
