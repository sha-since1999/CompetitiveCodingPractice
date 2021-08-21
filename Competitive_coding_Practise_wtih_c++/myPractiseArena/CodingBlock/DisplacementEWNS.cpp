#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x = 0, y = 0;
    char ch = cin.get();
    while (ch != '\n')
    {
        if (ch == 'N' or ch == 'n')
            y++;
        if (ch == 'W' or ch == 'w')
            x--;
        if (ch == 'E' or ch == 'e')
            x++;
        if (ch == 'S' or ch == 's')
            y--;

        ch = cin.get();
    }
    cout << "x: " << x << " y: " << y << endl;
    cout << "displacement: " << sqrt(x * x + y * y) << endl;
    return 0;
}