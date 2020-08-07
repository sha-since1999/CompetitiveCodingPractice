#include <bits/stdc++.h>
using namespace std;
template <class T>
class Graph
{
private:
    int V;

    map<T, list<T>> adjlist;

public:
    Graph(int v)
    {
        this->V = v;
        // adjlist = new map<T,list<T>>[v + 1];
    }
    void addEadge(T u, T v, bool bider = true)
    {
        adjlist[u].push_back(v);
        if (bider)
            adjlist[v].push_back(u);
    }
    void printGraph()
    {

        for (auto mp : adjlist)
        {
            cout << mp.first << "-->";
            for (auto neighbour : mp.second)
                cout << neighbour << "-->";
            cout << endl;
        }
    }
    void bfs(T v)
    {
        map<T, bool> isVisited;
        cout << v << "-->";
        queue<T> q;
        q.push(v);
        isVisited[v] = true;
        while (!q.empty())
        {
            T p = q.front();
            q.pop();
            for (auto val : adjlist[p])
            {
                if (!isVisited[val])
                {
                    isVisited[val] = true;
                    cout << val << "-->";
                    q.push(val);
                }
            }
        }
        cout << endl;
    }
    map<T, bool> isVisited;
    void dfs(T v)
    {
        cout << v << "-->";
        isVisited[v] = true;
        for (auto m : adjlist[v])
            if (!isVisited[m])
                dfs(m);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Graph<string> gp(4);

    gp.addEadge("lko", "stn");
    gp.addEadge("stn", "be");
    gp.addEadge("lko", "mrf");
    gp.addEadge("lko", "be");
    gp.addEadge("be", "mrf");
    gp.printGraph();
    cout << "bfs: \n";
    gp.bfs("lko");
    cout << "dfs: \n";
    gp.dfs("lko");
    return 0;
}