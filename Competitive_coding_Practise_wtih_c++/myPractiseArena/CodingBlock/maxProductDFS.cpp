#include <bits/stdc++.h>
using namespace std;
int a[20][20];
int solution(int i, int j)
{
    int s[9] = {0};
    if (j + 4 < 20)
    {
        for (int x = j; x < j + 4; x++)
            s[1] += a[i][x];
    }
    if (i + 4 < 20)
    {
        for (int x = i; x < i + 4; x++)
            s[2] += a[x][j];
    }
    if (j - 4 > 0)
    {
        for (int x = j; x > j - 4; x--)
            s[3] += a[i][x];
    }
    if (i - 4 > 0)
    {
        for (int x = i; x > i - 4; x--)
            s[4] += a[x][j];
    }
    if (j + 4 < 20 and i + 4 < 20)
    {
        int n = 4;
        while (n--)
        {
            s[5] += a[i++][j++];
        }
    }
    if (j + 4 < 20 and i - 4 > 0)
    {
        int n = 4;
        while (n--)
        {
            s[6] += a[i--][j++];
        }
    }
    if (j - 4 > 0 and i + 4 < 20)
    {
        int n = 4;
        while (n--)
        {
            s[7] += a[i++][j--];
        }
    }
    if (j - 4 > 0 and i - 4 > 0)
    {
        int n = 4;
        while (n--)
        {
            s[8] += a[i--][j--];
        }
    }
    return *max_element(s, s + 9);
}
int main()
{

    int n = 20;
    int res[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = solution(i, j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}