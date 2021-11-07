#include <bits/stdc++.h>
#include "input.h"
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int slow = a[0];
    int fast = a[0];
    do
    {
        slow = a[slow];
        fast = a[a[fast]];
    } while (slow != fast);
    slow = a[0];
    while (slow != fast)
    {
        slow = a[slow];
        fast = a[fast];
    }
    cout << slow << endl;
    return 0;
}
// 6
// 4 3 1 5 0 4
// o/p - 4