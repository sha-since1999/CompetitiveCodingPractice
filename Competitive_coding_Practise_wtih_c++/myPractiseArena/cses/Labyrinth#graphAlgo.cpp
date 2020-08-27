#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct par
{
    int x;
    int y;
    char dir;
};
par pr[1010][1010];
int n = 0, m = 0;
int vis[1010][1010];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char dir[4] = {'L', 'R', 'U', 'D'};
char ar[1010][1010];
int Ax, Ay, Bx, By;
bool is_valid(int i, int j)

{
    if (i < 0 or i >= n or j < 0 or j >= m or vis[i][j] or ar[i][j] == '#')
        return false;
    return true;
}
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    pr[x][y] = {-1, -1, 'A'};
    vis[x][y] = 1;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        x = curr.first;
        y = curr.second;
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            char c = dir[i];
            if (is_valid(a, b))
            {
                vis[a][b] = 1;

                pr[a][b] = {x, y, c};
                if (a == Bx and b == By)
                    return;
                q.push({a, b});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> ar[i][j];
            if (ar[i][j] == 'A')
                Ax = i, Ay = j;
            if (ar[i][j] == 'B')
                Bx = i, By = j;
        }

    pr[Bx][By] = {-1, -1, '$'};

    bfs(Ax, Ay);

    if (pr[Bx][By].dir != '$')
    {
        string path = "";
        int dist = 1;
        int a = pr[Bx][By].x, b = pr[Bx][By].y;
        path.push_back(pr[Bx][By].dir);
        char c = 'a';
        while (pr[a][b].x != -1)
        {
            // cout << pr[a][b].x << " " << pr[a][b].y << " " << pr[a][b].dir << endl;
            path.push_back(pr[a][b].dir);
            c = pr[a][b].dir;
            int x = a;
            a = pr[a][b].x, b = pr[x][b].y;
            dist++;
        }
        reverse(path.begin(), path.end());
        cout << "YES" << endl;
        cout << dist << endl;
        cout << path << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
