#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "abctafdgab";
    int n = s.size();
    int mid = n / 2;

    if (n & 1)
    {
        int i = 0;
        while (i < mid)
        {
            string x = s.substr(0, mid - i);
            string y = s.substr(mid + 1 + i, mid - i);
            // cout << x << " " << y << endl;
            if (x.compare(y) == 0)
            {
                cout << x.size() << endl;
                break;
            }
            i++;
        }
    }
    else
    {
        int i = 0;
        while (i < mid - 1)
        {
            string x = s.substr(0, mid - i);
            string y = s.substr(mid  + i, mid - i);
            // cout << x << " " << y << endl;
            if (x.compare(y) == 0)
            {
                cout << x.size() << endl;
                break;
            }
            i++;
        }
    }

    return 0;
}

// string s = "abcdabc";
// int l = s.length();
// int i = 0, j = l / 2;
// // cout << s.substr(0, j - i) << " " << s.substr(j + i, l - 1) << " ";

// if (l & 1)
//     while ((s.substr(0, j - i)).compare(s.substr(j + i + 1, l - 1)) != 0 and i < l / 2 - 1)
//     {
//         i++;
//     }
// else
//     while ((s.substr(0, j - i)).compare(s.substr(j + i, l - 1)) != 0 and i < l / 2 - 1)
//     {
//         i++;
//     }
// cout << j - i;