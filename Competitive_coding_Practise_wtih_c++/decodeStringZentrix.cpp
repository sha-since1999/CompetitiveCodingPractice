#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[] = "4,6-8,9,10-15,34,19,45-48";
    int x = s[0] - '0', y = 0;
    for (int i = 1; s[i]; i++)
    {

        if (s[i] != ',' and s[i] != '-')
        {
            if (y)
                y = y * 10 + (s[i] - '0');
            else if (s[i - 1] == '-')
                y = s[i] - '0';
            else if (x)
                x = (x * 10) + (s[i] - '0');
            else if (s[i - 1] == ',')
                x = s[i] - '0';
        }
        if (s[i] == ',' or !s[i + 1])
        {
            if (!y)
                y = x;
            for (int k = x; k <= y; k++)
                cout << k << endl;
            x = 0;
            y = 0;
        }
    }
    return 0;
}
