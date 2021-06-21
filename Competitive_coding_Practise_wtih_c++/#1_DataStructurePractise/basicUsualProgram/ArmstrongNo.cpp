#include <bits/stdc++.h>
using namespace std;
bool armstrong(int n)
{

    int tmp = n;
    int noOfDigit = 0;
    int s = 0;

    //count no. of digit
    int tp = n;
    while (tp)
        tp /= 10, noOfDigit++;

    while (tmp)
    {
        int d = tmp % 10;
        s += pow(d, noOfDigit);
        tmp /= 10;
    }

    if (s == n)
        return true;
    else∑
        return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        if (armstrong(i))
            cout << "no is armstrong " << i << endl;

    return 0;
}