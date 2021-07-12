#include <bits/stdc++.h>
#include "input.h"
using namespace std;

#define INF 9999999

int V;

void floydWarshall(vector<int> *graph)
{
    int dist[V + 1][V + 1], i, j, k;

    for (i = 1; i <= V; i++)
        for (j = 1; j <= V; j++)

            dist[i][j] = graph[i][j];

    for (k = 1; k <= V; k++)
    {
        for (i = 1; i <= V; i++)
        {

            for (j = 1; j <= V; j++)
            {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int r;
    cin >> r;
    vector<int> rest(r);
    for (int i = 0; i < r; i++)
        cin >> rest[i];

    //print shortest path
    for (int i = 1; i <= V; i++)
    {
        int mn = INT32_MAX;
        for (int j : rest)
        {
            mn = min(dist[i][j], mn);
        }
        cout << mn << endl;
    }
}

int main()
{

    // int graph[V][V] = {{0, 5, INF, 10},
    //                    {INF, 0, 3, INF},
    //                    {INF, INF, 0, 1},
    //                    {INF, INF, INF, 0}};

    int n, e;
    cin >> n >> e;
    V = n;
    vector<int> graph[n + 1];
    for (int i = 0; i <= n; i++)
        graph[i].assign(n + 1, INF);

    for (int i = 1; i <= e; i++)
    {
        int p, q, t;
        cin >> p >> q >> t;
        graph[p][q] = t;
        graph[q][p] = t;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (i == j)
                graph[i][j] = 0;
    }

    floydWarshall(graph);

    return 0;
}

// 5 4
// 1 3 4
// 2 3 5
// 4 5 8
// 5 1 3
// 2
// 3
// 4