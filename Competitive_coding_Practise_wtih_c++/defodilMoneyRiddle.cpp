#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ravimx = 0;
    int i = 0, j = n - 1;
    bool flag = true;
    while (i <= j)
    {
        if (flag)
            if (a[i] >= a[j])
            {
                ravimx += a[i];
                i++;
            }
            else
            {
                ravimx += a[j];
                j--;
            }
        else
        {
            if (a[i] >= a[j])
                i++;
            else
                j--;
        }
        flag = flag ? false : true;
    }

    cout << ravimx << endl;

    return 0;
}

// i/p
// 6
// 5 2 4 3 7 10

// o/p
// 19