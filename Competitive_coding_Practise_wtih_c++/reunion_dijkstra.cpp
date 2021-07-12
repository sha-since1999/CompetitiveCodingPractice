#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj[n + 1];
    // set<int> st;
    for (int i = 0; i < e; i++)
    {
        int p, q, t;
        cin >> p >> q >> t;
        adj[p].emplace_back(q, t);
        adj[q].emplace_back(p, t);
        // st.insert(p);
        // st.insert(q);
    }
    int r;
    cin >> r;
    vector<int> rest;
    for (int i = 0; i < r; i++)
    {
        int tmp;
        cin >> tmp;
        rest.push_back(tmp);
    }

    for (int node = 1; node <= n; node++)
    {
        // dijikstra algo
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT32_MAX);
        dist[node] = 0;
        pq.push({0, node});

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

        // for (int i = 1; i <= n; i++)
        //     cout << dist[i] << " ";
        // cout << endl;

        int mn = INT32_MAX;
        for (int r : rest)
        {
            // cout << dist[r] << " ";
            mn = min(dist[r], mn);
        }
        cout << mn << endl;
    }

    return 0;
}
