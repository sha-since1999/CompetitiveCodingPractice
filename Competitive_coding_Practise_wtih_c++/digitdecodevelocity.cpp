#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int fd, ld;
    ld = n % 10;

    string s = to_string(n);
    fd = int(s[0] - '0');

    if (fd == 1)
        cout << "H";
    else
        cout << "K";
    if (n & 1)
        cout << "Y";
    else
        cout << "X";
    if (ld == 2)
        cout << "K";
    else
        cout << "H";


    cout << endl;
    return 0;
}