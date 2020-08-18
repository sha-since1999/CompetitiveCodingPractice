#include<bits/stdc++.h>
using namespace std;
// this is optimal solution  because naive approach is very simple
int countBits(int n)
{
    int cnt=0;
    while (n) n&=(n-1), cnt++;
    return cnt;
}
int sumOfBitsInGivenRange(int i, int j)
{
    int  cnt=0;
    for (;i<=j;i++)
    {
        if (i&1==0)
        {
            cnt+=2*countBits(i)+1;
            continue;
        }
        cnt+=countBits(i);
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout<<sumOfBitsInGivenRange(10, 15);

    return 0;
}

// in this problem you have to find sum of bits  of a number  in given Range in impilicit; 



