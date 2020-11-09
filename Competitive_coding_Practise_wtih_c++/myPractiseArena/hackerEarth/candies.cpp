#include <bits/stdc++.h>
using namespace std;
int main()
{
    int d;
    cin >> d;
    if (d > 10 || d==0)
    {
        cout << "INVALID INPUT"<<endl;
        cout << "NUMBER OF CANDIES AVAILABE:10" << endl;
        
    }
    else
    {
        if (10 - d <= 5)
        {
            cout << "NUMBER OF CANDIES SOLD:" << d << endl
            ;
            cout << "NUMBER OF CANDIES AVAILABE:10"<<endl;
        }
        else
        {
            cout << "NUMBER OF CANDIES SOLD:" << d<<endl;
            cout << "NUMBER OF CANDIES AVAILABE:" << 10 - d<<endl;
        }
    }
}/