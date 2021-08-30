#include <bits/stdc++.h>
#include "input.h"
using namespace std;
int tile(int n)
{
    if (n < 4)
        return 1;
    return tile(n - 1) + tile(n - 4);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << tile(4);
    return 0;
}

// brick wall of size 4 * N and tile of size 4 * 1, you have to find out
// no of ways to arrange the tiles on wall.