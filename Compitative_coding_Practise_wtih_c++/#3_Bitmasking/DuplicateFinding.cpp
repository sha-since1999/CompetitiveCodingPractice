#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "findIng";
    long int H = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        long int x = 1;
        int shift = 0;
        shift = s[i] < 97 ? s[i] - 65 : s[i] - 97;
        x = x << shift;
        if ((H & x) > 0)
            cout << "key   " << s[i] << "  have duplicate int the string " << endl;
        else
            H = x | H;
    }
    return 0;
}