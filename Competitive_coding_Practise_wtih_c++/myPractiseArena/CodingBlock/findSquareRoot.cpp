#include <bits/stdc++.h>
using namespace std;

int main()
{
    float n;
    int pdigit;
    cout << "\nEnter no to find its square root : ";
    cin >> n;
    cout << "\nEnter number of precision digit require: ";
    cin >> pdigit;

    float d = 1;
    float p = 1;
    while (pdigit--)
    {
        d /=  10;
        while (p * p < n)
        {
            p += d;
            // cout << p << endl;
        }
        p -= d;
        // cout << d << endl;
    }
    cout << p << endl;
    return 0;
}