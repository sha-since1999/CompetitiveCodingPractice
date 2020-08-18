#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[]={ 1, 1, 2, 3, 3, 4, 5, 5, 6, 4, 6 };
    int  n= sizeof(a)/sizeof(a[0]);

    // to find  a unique no just take xor of all no   
    // so that same no would be distroy
    int uniqueNo=0;
    for (int i=0;i<n;i++) uniqueNo^=a[i];
    cout<<uniqueNo<<endl;

    return 0;
}