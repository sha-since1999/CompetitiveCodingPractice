#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> primes;
vector<int> ar[10001];
int dist[10001];
int vis[10001];
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
bool isValid(int a, int b)
{
    int cnt = 0;
    while (a > 0)
    {
        if (a % 10 != b % 10)
            cnt++;
        a /= 10;
        b /= 10;
    }
    if (cnt == 1)
        return true;
    return false;
}
void bfs(int node)
{
    vis[node] = 1;
    dist[node] = 0;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int child : ar[curr])
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                dist[child] = dist[curr] + 1;
            }
    }
}
void buildGraph()
{
    for (int i = 1000; i <= 9999; i++)
    {
        if (isPrime(i))
            primes.push_back(i);
    }

    for (int i = 0; i < primes.size(); i++)
    {
        for (int j = i + 1; j < primes.size(); j++)
        {
            int a = primes[i];
            int b = primes[j];
            if (isValid(a, b))
                ar[a].push_back(b), ar[b].push_back(a);
        }
    }
}
int main()
{
    buildGraph();
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < 10001; i++)
            vis[i] = 0, dist[i] = -1;

        bfs(n);
        if (dist[m] == -1)
            cout << "Impossible" << endl;
        else
            cout << dist[m] << endl;
    }

    return 0;
}