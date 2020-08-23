#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n = 0, m = 0;
int vis[1010][1010];
int dist[1010][1010];
string path[1010][1010];
char ar[1010][1010];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
string dir[4] = {"L", "R", "U", "D"};
bool is_valid(int i, int j)
{
    if (i < 0 or i >= n or j < 0 or j >= m or vis[i][j] or ar[i][j] == '#')
        return false;
    return true;
}
void bfs(int x, int y, int d)
{
    queue<pair<pair<int, int>, string>> q;
    q.push({{x, y}, ""});
    path[x][y] = "";
    dist[x][y] = 0;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = curr.first.first + dx[i];
            int b = curr.first.second + dy[i];
            string c = curr.second + dir[i];
            if (is_valid(a, b))
            {
                vis[a][b] = 1;
                dist[a][b] = dist[curr.first.first][curr.first.second] + 1;
                path[a][b] = c;
                q.push({{a, b}, c});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    int Ax, Ay, Bx, By;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> ar[i][j];
            if (ar[i][j] == 'A')
                Ax = i, Ay = j;
            if (ar[i][j] == 'B')
                Bx = i, By = j;
            path[i][j] = "";
            dist[i][j] = 0;
        }

    bfs(Ax, Ay, 0);
    if (dist[Bx][By])
    {
        cout << "YES" << endl;
        cout << dist[Bx][By] << endl;
        cout << path[Bx][By] << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
