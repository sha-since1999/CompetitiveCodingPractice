#include <bits/stdc++.h>
// #include "input.h"
using namespace std;
int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 or j == 0 or i == 4 or j == 4)
                cout << "* ";
            else
                cout << "  ";
        }

        cout << endl;
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 or i == j)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    return 0;
}
