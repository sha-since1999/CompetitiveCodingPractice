#include<bits/stdc++.h>
using namespace std;
int uniqueNoThree(int *a, int n)
{
    int h[32]={ 0 };
    for (int k=0;k<n;k++)
    {
        int num = a[k];
        int i=0;
        while (num)
        {
            h[i]+=num&1;
            num=num>>1;
            i++;
        }
    }
    int ans=0;
    for (int i =0;i<32;i++)
    {
        h[i]%=3;
        ans+=(h[i]*(1<<i));
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[]={ 2, 3, 4, 5, 5, 5, 2, 3, 4, 2, 3, 4, 9 };
    int n =sizeof(a)/sizeof(a[0]);
    cout<<uniqueNoThree(a, n)<<endl;
    return 0;
}