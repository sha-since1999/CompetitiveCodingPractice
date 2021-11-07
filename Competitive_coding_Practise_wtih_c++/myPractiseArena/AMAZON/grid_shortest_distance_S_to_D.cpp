#include <bits/stdc++.h>
#include "input.h"
using namespace std;
struct item
{
    int x, y, d;
    item(int x, int y, int d) : x(x), y(y), d(d) {}
};
int main()
{
    int n = 4, m = 4;
    char grid[n][m] = {
        {'0', '*', '0', 's'},
        {'*', '0', '*', '*'},
        {'0', '*', '*', '*'},
        {'d', '*', '*', '*'}};
    int dx[] = {0, 1, -1, 0};
    int dy[] = {-1, 0, 0, 1};
    int vis[n + 1][m + 1];
    int x, y, d = 0;
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '0')
                vis[i][j] = 1;
            else
                vis[i][j] = 0;
            if (grid[i][j] == 's')
                x = i, y = j;
        }
    }

    queue<item> q;
    q.push({x, y, d});
    while (!q.empty())
    {
        item box = q.front();
        x = box.x;
        y = box.y;
        d = box.d;
        q.pop();
        if (grid[x][y] == 'd')
        {
            res = d;
        }
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a < n and b < m and a >= 0 and b >= 0 and vis[a][b] == 0)
            {
                q.push({a, b, d + 1});
                vis[a][b] = 1;
            }
        }
    }
    cout << res << endl;
    return 0;
}