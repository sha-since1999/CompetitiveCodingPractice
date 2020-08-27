#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n = 0, m = 0;
int vis[1001][1001];
char ar[1001][1001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int cnt = 0;
bool is_valid(int i, int j)
{
    if (i < 0 or i >= n or j < 0 or j >= m or vis[i][j] or ar[i][j] == '#')
        return false;
    return true;
}
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if (is_valid(a, b))
            dfs(a, b);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> ar[i][j];

    int room_count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (is_valid(i, j))
            {
                room_count++;
                dfs(i, j);
            }
    cout << room_count << endl;
    return 0;
}