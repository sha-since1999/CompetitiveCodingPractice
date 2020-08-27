#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

using namespace std;
static int i = 0;
char querry(int y, int x)
{
    ++i;

    if (y > x)
    {
        if (i % 5 != 0)
            return 'L';
        else
            return 'G';
    }
    else if (y < x) //G
    {

        if (i % 5 != 0)
            return 'G';
        else
            return 'L';
    }
    else
    {
        return 'E';
    }
    return 0;
}
char response;
int y;
int N;
int x;
int main()
{
    cin >> N;

    if (N == 0)
    {
      exit(0);
    }
    else
    {
        x = time(0) % N;
        x = x % 120 + 1;
        cout << x;
    }

    while (response != 'E')
    {
        cin >> y;
        if(y>N||y<1)
            exit(0);

        response = querry(y, x);

        cout << response << endl;
    }
    return 0;
}