#include <bits/stdc++.h>
using namespace std;
#define INF INT32_MAX

int main()
{
    int p, q, t, n, ed;
    cin >> n >> ed;
    for (int e = 0; e < ed; e++)
    {
        cin >> p >> q >> t;
        adj[p].push_back({q, t});
        adj[q].push_back({p, t});
    }

    // priority_queue<int> Q // this is max priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // for min priority queue
    vector<pair<int, int>> adj[10001];
    vector<int> dist(n + 1, INF);
    //intialisation
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty())
    {

        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();
        for (auto edge : adj[curr])
        {
            if (curr_d + edge.second < dist[edge.first])
            {
                dist[edge.first] = curr_d + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}

// 6 9
// 1 2 4
// 1 6 2
// 2 3 5
// 2 6 1
// 6 3 8
// 6 5 10
// 3 4 6
// 3 5 3
// 5 4 5
