#include <bits/stdc++.h> // this partially accepted
using namespace std;
typedef long long ll;
void sahu()
{
#ifndef MY_OFFLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !MY_OFFLINE_JUDGE
}
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
int Ax, Ay, Bx[1001], By[1001];
vector<int> monsters;
bool is_valid(int i, int j, int mx, int my)
{
    if (i < 0 or i >= n or j < 0 or j >= m or mx < 0 or mx >= n or my < 0 or j >= mor vis[i][j] or ar[i][j] == '#' or ar[i][j] == 'M')
        return false;
    return true;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    pr[x][y] = {x, y, 'A'};
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
                q.push({a, b});
            }
        }
    }
}
void dfs(int x, int y, int mx, int my, int px, int py, char c)
{
    pr[x][y] = {px, py, c};
    vis[x][y] = 1;
    for (auto m : monsters)
    {
        int mx = m.first;
        int my = m.second;
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            int ma = mx + dx[i];
            int mb = my + dy[i];
            char c = dir[i];

            if (is_valid(a, b, ma, mb))
                dfs(a, b, ma, mb x, y, c);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sahu();
    cin >> n >> m;
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> ar[i][j];
            if (ar[i][j] == 'M')
                monsters.push_back({i, j});
            if (ar[i][j] == 'A')
                Ax = i, Ay = j;
            if ((i == 0 or i == n - 1) and ar[i][j] == '.')
                Bx[k] = i, By[k] = j, k++;
            else if ((j == 0 or j == m - 1) and ar[i][j] == '.')
                Bx[k] = i, By[k] = j, k++;
        }
    int szk = k;
    while (k--)
    {
        pr[Bx[k]][By[k]] = {-1, -1, '$'};
        // cout << ar[Bx[k]][By[k]] << endl;
    }
    // bfs(Ax, Ay);

    for (auto m : monsters)
        if (!vis[i][j] or !vis[m.first][m.second])
            dfs(Ax, Ay, m.first, m.second, 'A');

    // cout << pr[Ax][Ay].dir << endl;
    bool dont = 1;
    while (szk--)
        if (pr[Bx[szk]][By[szk]].dir != '$')
        {
            // for (int i = 0; i < n; i++)
            //     for (int j = 0; j < m; j++)
            //         cout << pr[i][j].x << " " << pr[i][j].y << " " << pr[i][j].dir << endl;
            string path = "";
            int dist = 1;
            int a = pr[Bx[szk]][By[szk]].x, b = pr[Bx[szk]][By[szk]].y;
            path.push_back(pr[Bx[szk]][By[szk]].dir);
            char c;
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
            dont = 0;
            break;
        }
    if (dont)
        cout << "NO" << endl;
    return 0;
}
