#include<bits/stdc++.h>
using namespace std;

void isSubsetSum(int *a, int n, int *q, int m)
{

    bitset<1000>b(1); // not here bitset size should be max sum of array
    for (int i =0;i<n;i++) b|=b<<a[i];

    // query checking
    for (int i=0;i<m;i++)
    {
        if (b[q[i]]) cout<<"SubsetExit"<<endl;
        else cout<<"Subset Not Exist"<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[]={ 1, 2, 3, 7 }; // given array
    int n=sizeof(a)/sizeof(a[0]);
    int q[]={ 3, 5, 12, 20 };// query array
    int m=sizeof(q)/sizeof(q[0]);

    isSubsetSum(a, n, q, m);


    return 0;
}