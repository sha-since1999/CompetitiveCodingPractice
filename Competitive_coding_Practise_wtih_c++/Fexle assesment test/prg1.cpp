#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s = "HARRY";
    // cin >> s;
    for (int i = 0; i < s[i]; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "  ";
        }
        for (int j = i; s[j] != '\0'; j++)
            cout << s[j] << " ";
        cout << endl;
    }

    return 0;
}
// H A R R Y 
//   A R R Y 
//     R R Y 
//       R Y 
//         Y