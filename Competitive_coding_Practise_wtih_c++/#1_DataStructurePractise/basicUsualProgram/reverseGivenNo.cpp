#include <bits/stdc++.h>
using namespace std;
int reverseDigit(int n)
{
    int s = 0;
    while (n)
    {
        int d = n % 10;
        n /= 10;
        s = s * 10 + d;
    }
    return s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << reverseDigit(n) << endl;
    return 0;
}