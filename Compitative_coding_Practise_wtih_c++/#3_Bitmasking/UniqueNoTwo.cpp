#include<bits/stdc++.h>
using namespace std;
void findUniqueNoTwo(int *a, int n)
{
    int res=0;
    for (int i=0;i<n;i++) res^=a[i];
    int idx=0;
    while (res)
    {
        if (res&(1<<idx))
            break;
        idx++;
    }
    int mask = 1<<idx;
    int b = res;
    for (int i =0;i<n;i++)
    {
        if (a[i]&mask)
            b^=a[i];
    }
    int c = res^b;
    cout<<b<<" "<<c<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[]={ 2, 3, 4, 13, 5, 6, 2, 3, 4, 5, 6, 9 };
    int n=sizeof(a)/sizeof(a[0]);
    findUniqueNoTwo(a, n);

    return 0;
}