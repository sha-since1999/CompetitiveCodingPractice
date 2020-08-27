#include <bits/stdc++.h>
using namespace std;
#define I INT_MAX
#define size 7

class Graph
{
    int cost[size][size] ={ { I, 2, I, 6, I },
        { 2, I, 3, 8, 5 },
        { I, 3, I, I, 7 },
        { 6, 8, I, I, 9 },
        { I, 5, 7, 9, I } };
    int adjcency[7][7] ={ { 0, 1, 1, 1, 0, 0, 0 }, { 1, 0, 1, 0, 0, 0, 0 }, { 1, 1, 0, 1, 1, 0, 0 }, { 1, 0, 1, 0, 1, 0, 0 }, { 0, 1, 1, 0, 0, 1, 1 }, { 0, 0, 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 1, 0, 0 } };
    int eadge[9][3] ={ { 1, 2, 28 }, { 1, 6, 10 }, { 2, 3, 16 }, { 2, 7, 14 }, { 3, 4, 12 }, { 4, 5, 22 }, { 4, 7, 18 }, { 5, 6, 25 }, { 5, 7, 24 } };
    int n = size;
    int t[2][size];
    int visited[size] ={ 0 };
    int SET[9] ={ -1, -1, -1, -1, -1, -1, -1, -1, -1 }; //for kruskals to check cycles
    int near[9] ={ I, I, I, I, I, I, I, I, I };         // to find next nearest vertices in Graph

public:
    void dfs(int);
    void bfs(int);
    void prims(void);
    void kruskals(void);
    void unionSet(int, int);
    int find(int);
};
void Graph::unionSet(int u, int v)
{
    if (SET[u] < SET[v])
    {
        SET[u] = SET[v] + SET[u];
        SET[v] = u;
    }

    else
    {
        SET[v] = SET[v] + SET[u];
        SET[u] = v;
    }
}
int Graph::find(int u)
{
    int x = u, v = 0;
    while (SET[x] > 0)
    {
        x = SET[x];
    }
    //collapsing
    while (u != x)
    {
        v = SET[u];
        SET[u] = x;
        u = v;
    }
    return x;
}
void Graph::dfs(int i)
{
    cout << i << " ";
    visited[i] = 1;
    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && adjcency[i][v] == 1)
            dfs(v);
    }
}
void Graph::bfs(int i)
{
    int visited[size + 1] ={ 0 };
    int u;
    queue<int> qu;
    cout << i << " ";
    visited[i] = 1;
    qu.push(i);
    while (!qu.empty())
    {
        u = qu.front();
        qu.pop();
        for (int v = 0; v < n; v++)
            if (adjcency[u][v] == 1 && visited[v] == 0)
            {
                // cout << "(" u << "," << v << ")" << endl;
                cout << v << " ";
                visited[v] = 1;
                qu.push(v);
            }
    }
}
void Graph::prims(void)
{ //first of all find minimum cost eadge in the Graph
    int u, v, i, j, k, min = I;
    int visited[size] ={ 0 };
    int t[2][size];
    int n = 5;
    int total_cost = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    //first step  ... first min eadgein table
    t[0][0] = u;
    t[1][0] = v;
    near[u] = -1;
    near[v] = -1;
    // put all near vertices in the near table
    for (int j = 0; j < n; j++)
    {
        if (near[j] != -1)
        {
            if ((cost[u][j] < cost[v][j]))
                near[j] = u;
            else
                near[j] = v;
        }
    }
    cout << "vertex:    (" << t[0][0] << "," << t[1][0] << ")    "
        << "cost:  " << min << endl;

    // from here all repeated step for prims
    for (i = 1; i < n - 1; i++)
    {
        //find nearest vertice in the near table
        min = I;
        int k = -1;
        for (int j = 0; j < n; j++)
        {
            // cout << near[j] << endl;
            // // cout << cost[j][near[j]] << endl;
            if (near[j] != -1)
            {
                if ((cost[j][near[j]] < min))
                {
                    min = cost[j][near[j]];
                    k = j;
                }
            }
        }
        t[0][i] = near[k];
        t[1][i] = k;
        near[k] = -1;

        // update the value of near table  in Grpah
        for (int j = 0; j < n; j++)
        {
            if ((cost[j][k] < cost[j][near[j]]) && (near[j] != -1))
                near[j] = k;
        }
        cout << "vertex:    (" << t[0][i] << "," << t[1][i] << ")    "
            << "cost:  " << min << endl;
        total_cost += min;
    }
    cout << "total minimum cost :" << total_cost << endl;
}
void Graph::kruskals(void)
{
    int visited[size] ={ 0 };
    int t[2][size];
    int n = 9;
    int V = 7;
    int i = 0, j = 0, u = 0, v = 0, k = 0, min = I;
    int total_cost = 0;
    while (i < V - 1)
    {
        min = I;
        for (int j = 0; j < n; j++)
        {
            if (eadge[j][2] < min && visited[j] == 0)
            {
                min = eadge[j][2];
                u = eadge[j][0];
                v = eadge[j][1];
                k = j;
            }
        }

        visited[k]++;
        if (find(u) != find(v))
        {
            t[0][i] = u;
            t[1][i] = v;
            total_cost += min;
            cout << "(" << t[0][i] << "," << t[1][i] << ")       cost:" << min << endl;
            unionSet(find(u), find(v));
            i++;
        }
    }
    cout << "total minimum cost: " << total_cost << endl;
}
int main()
{
    Graph gp;
    cout << "\nBFS: ";
    gp.bfs(5);
    cout << "\nDFS: ";
    gp.dfs(5);
    cout << endl;
    cout << "<-----Prims here----->" << endl;
    gp.prims(); // check matrix  size first (5)
    cout << "<-----Kruskals here---->" << endl;
    gp.kruskals(); //heck matrix  size first(9)
    return 0;
}

//everything is well tested and verified here
// now you learn various method of finding cycle and  do some leetcode practise 