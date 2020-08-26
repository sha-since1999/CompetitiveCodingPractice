#include <bits/stdc++.h>
//#include "sahu.h"
using namespace std;
int N;
int par[1010];
int vis[1010];
int lca(int a, int b)
{
    for (int i = 1; i <= N; i++)
        vis[i] = 0;
    while (par[a] != a)
        vis[a] = 1, a = par[a];
    vis[a] = 1;
    // note: all nodes from a to root ill mark as visited
    // just now check intersection point of for the path  from b ro root
    while (vis[b] != 1)
        b = par[b];
    return b;
}
int main()
{
    int T;
    cin >> T;
    int case_no = 1;
    while (T--)
    {

        cin >> N;
        for (int i = 1; i <= N; i++)
            par[i] = i;
        for (int i = 1; i <= N; i++)
        {
            int m;
            cin >> m;
            while (m--)
            {
                int a;
                cin >> a;
                par[a] = i;
            } // note_ here  : there is rooted tree hence parent of root is always be remain root;
        }

        cout << "Case " << case_no++ << ":" << endl;
        int q, a, b;
        cin >> q;
        while (q--)
        {
            cin >> a >> b;
            cout << lca(a, b) << endl;
        }
    }
    return 0;
}

// successfull submission