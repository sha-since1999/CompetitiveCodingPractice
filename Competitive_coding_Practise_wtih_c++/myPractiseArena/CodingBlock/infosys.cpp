#include <bits/stdc++.h>
#include "input.h"
using namespace std;

bool isLeapYear(int x)
{
    if ((x % 4 == 0 and x % 100 != 0) or (x % 400 == 0))
        return true;

    return false;
}
int main()
{
    int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char s[1000];
    cin >> s;
    int year, month, day, ans;
    year = stoi(strtok(s, "-"));
    month = stoi(strtok(NULL, "-"));
    day = stoi(strtok(NULL, "-"));

    if (isLeapYear(year) and month > 2)
        ans++;
    month--;
    while (month > 0)
    {
        ans += d[month--];
    }
    ans += day;
    cout << ans << endl;
    return 0;
}

// 2012 - 03 - 23
// ans = 83