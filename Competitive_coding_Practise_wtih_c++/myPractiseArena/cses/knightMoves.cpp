#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n = 8, m = 8;
int vis[9][9];
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, -2, 2, -2, 2};
int dist[100][100];
int Ax, Ay, Bx, By;
bool is_valid(int i, int j)
{
    if (i < 0 or i >= n or j < 0 or j >= m or vis[i][j])
        return false;
    return true;
}
int dfs(int x, int y, int d)
{
    if (x == Bx, y == By)
        return d;
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if (is_valid(a, b))
            return dfs(a, b, d + 1);
    }
    return d;
}
int bfs(int x, int y)
{
    if (x == Bx and y == By)
        return 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty())
    {
        auto curr = q.front();
        x = curr.first;
        y = curr.second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            if (is_valid(a, b))
            {
                vis[a][b] = 1;
                dist[a][b] = dist[x][y] + 1;
                if (a == Bx and b == By)
                    return dist[a][b];
                q.push({a, b});
            }
        }
    }
    return -1;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                dist[i][j] = 0;
                vis[i][j] = 0;
            }
        string sc, tg;
        cin >> sc >> tg;
        Ax = sc[0] - 'a', Ay = sc[1] - '1', Bx = tg[0] - 'a', By = tg[1] - '1';
        // cout << dfs(Ax, Ay, 0) << endl;
        cout << bfs(Ax, Ay) << endl;
    }
    return 0;
}

// notes : in min  path or distance question dfs fails  hence always try
//     bfs in such a question;

// here implement both from dfs and bfs bt dfs fails here you can check by uncommenting it;