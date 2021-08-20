// Jack and Jill were going through a jungle to city. They encountered a monster who
// told they will only be allowed to escape when they solve a puzzle for him. They
// didn't have a choice so they agreed.
// He states problem like : I have n buckets having 0 fruits in each bucket initially. I will
// give you n numbers denoting fruits required at nth position. But you need to keep 2
// simple rules:
// 1) Either you can increment fruit count by 1 in each bucket i.e. Incremental Operation
// 2) Or you can double the fruits in each bucket i.e. Doubling operation.
// Function Description:
// Provide implementation for method play_the_game(target).
// play_the_game has the following parameter(s):
// target: an integer list denoting numbers of fruits required at nth position.
// Example:
// Input: 23
// Output: 4
// Explanation:
// To get the target bucket from (0, 0), we
// first increment both elements by 1 (2
// operations), then double the array (1
// operation). Finally increment second
// element (1 more operation)
// Input: 16 16 16

#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool flag = true;
    int ans = n;
    bool oddflag;
    while (flag)
    {
        flag = false;
        oddflag = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] & 1 and a[i] > 1)
                oddflag = true;
            a[i] /= 2;
        }
        ans++;
        if (oddflag)
            ans++;

        for (int i = 0; i < n; i++)
            if (a[i] > 1)
            {
                flag = true;
                break;
            }
    }
    cout << ans << endl;
    return 0;
}
