#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int i, j;
        int flag;
        int x;
        int y;
        cin >> x >> y;
        if (x < 2)
            x = 2;
        for (i = x; i <= y; i++)
        {
            flag = 1;
            if (x % 2 == 0 && x != 2)
                continue;
            for (j = 2; j < (i / 2) + 1; j++)
            {
                if (i % j == 0)
                {
                    flag = 0;
                    break;
                }
            }

            if (flag == 1)
            {
                cout << i << endl;
            }
        }
        cout << endl;
    }
    return 0;
}