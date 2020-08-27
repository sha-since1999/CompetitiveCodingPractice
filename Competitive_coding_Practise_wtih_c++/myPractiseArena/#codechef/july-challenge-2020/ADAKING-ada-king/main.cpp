#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
    int T;
int x;
void pattern(int, int, int);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        int moves;
        cin >> moves;

        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                pattern(moves, i, j);
            }
            cout << endl;
        }
    }
    return 0;
}

void pattern(int moves, int i, int j)
{

    x = floor(moves / 8) + 2;
    moves = moves % 8;
    if (moves)
    {
        if (i == 1 && j == 1)
            cout << "O";
        else if (i == x || (i == (x - 1) && j > moves))
            cout << "X";
        else
            cout << ".";
    }
    else
    {
        if (i == 1 && j == 1)
            cout << "O";
        else if (i == x || (i == (x - 1) && j > moves))
            cout << "X";
        else
            cout << ".";
    }
}