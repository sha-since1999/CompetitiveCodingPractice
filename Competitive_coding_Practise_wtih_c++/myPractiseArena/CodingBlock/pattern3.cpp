#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j == i - 1 or j == 0)
                cout << i << " ";
            else
                cout << '0' << " ";
        }
        cout << endl;
    }

    return 0;
}

// 1 
// 2 2 
// 3 0 3 
// 4 0 0 4 
// 5 0 0 0 5 