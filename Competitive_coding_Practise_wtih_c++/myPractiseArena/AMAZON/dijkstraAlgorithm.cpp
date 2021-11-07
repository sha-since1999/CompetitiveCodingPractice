#include <bits/stdc++.h>
#include "input.h"
using namespace std;
void dijkstra(vector<pair<int, int>> *adj, int n)
{
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({1, 0});
    dist[1] = 0;
    while (!pq.empty())
    {
        auto curr = pq.top();
        int curr_d = curr.second;
        pq.pop();
        for (auto node : adj[curr.first])
            if (curr_d + node.second < dist[node.first])
            {
                dist[node.first] = curr_d + node.second;
                pq.push({node.first, dist[node.first]});
            }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }
}
void floyedWarshell(vector<pair<int, int>> *adj, int n)
{
    int dist[n + 1][n + 1];
    // create distance matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INT_MAX;
        }
        for (auto x : adj[i])
            dist[i][x.first] = x.second;
    }

    // algo strart here
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j] and dist[i][k] != INT_MAX and dist[k][j] != INT_MAX)
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // printing
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << dist[i][j] << " ";
        cout << '\n';
    }
}
int main()
{

    vector<pair<int, int>> adj[1000];

    int n, noe;
    cin >> n >> noe;
    for (int i = 0; i < noe; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        adj[x].push_back({y, d});
        adj[y].push_back({x, d});
    }

    dijkstra(adj, n);
    floyedWarshell(adj, n);

    return 0;
}