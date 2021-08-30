#include <bits/stdc++.h>
#include "input.h"
using namespace std;
char *gp(int input1, int input2, int input3)
{

    double r = (double)input2 / input1;
    // string s = to_string(pow(r, input3 - 2));

    double d = pow(r, input3 - 2);
    stringstream ss;
    string s;
    ss << d;
    ss >> s;

    return (char *)s.c_str();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    char *ch = gp(a, b, c);
    cout << ch[0] << endl;
    return 0;
}
