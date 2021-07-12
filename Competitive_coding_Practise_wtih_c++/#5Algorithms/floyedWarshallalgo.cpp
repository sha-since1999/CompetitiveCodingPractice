#include <bits/stdc++.h>
#include "input.h"
using namespace std;

#define INF 1e7

int V;

void floydWarshall(int **graph)
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

    //print shortest path
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "	 ";
            else
                cout << dist[i][j] << "	 ";
        }
        cout << endl;
    }
}

int main()
{
    // sample graph
    // int graph[V][V] = {{0, 5, INF, 10},
    //                    {INF, 0, 3, INF},
    //                    {INF, INF, 0, 1},
    //                    {INF, INF, INF, 0}};

    int n, e;
    cin >> n >> e;
    V = n;
    // graph declaration

    int **graph = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        graph[i] = new int[n + 1];

    //  graph initialisation

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = INF;
            if (i == j)
                graph[i][j] = 0;
        }
    }

    // input from user for weighted eadge
    for (int i = 1; i <= e; i++)
    {
        int p, q, t;
        cin >> p >> q >> t;
        graph[p][q] = t;
        graph[q][p] = t;
    }

    floydWarshall(graph);

    return 0;
}
