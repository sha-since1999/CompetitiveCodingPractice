#include <bits/stdc++.h>
#include "sahu.h"
using namespace std;
int main()
{
    int mxl, mnl, mxw, mnw;
    int cnt = 0;
    cin >> mnl >> mxl >> mnw >> mxw;
    for (int i = mnl; i <= mxl; i++)
    {
        for (int j = mnw; j <= mxw; j++)
        {
            int tnt = 0;
            int x = i < j ? i : j;
            int y = i > j ? i : j;
            while (x > 0 && y > 0)
            {
                int temp = x;
                x = abs(x - y);
                tnt++;
                if (temp > y && x == 1)
                {
                    tnt += y;
                    break;
                }
                if (temp < y && x == 1)
                {
                    tnt += temp;
                    break;
                }
                y = temp;
            }
            cout << tnt << "  ";
            cnt += tnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
// 5
// 7
// 3
// 4

// ans 24