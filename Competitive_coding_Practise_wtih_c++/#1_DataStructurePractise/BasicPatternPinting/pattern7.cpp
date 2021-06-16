#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    for(int i,j=1;i<=n;i++){
        for(j=1;j<=n-i;j++)cout<<" ";
        for(j=1; j<2*i;j++)cout<<"*";
        cout<<endl;
    }
    for(int j,i=1; i<=n;i++){
        for(  j=1;j<=i;j++)cout<<" ";
        for(j=1;j<2*(n-i);j++)cout<<"*";
        cout<<endl;
    }
    return 0;

}

// note it: in case of loop started from 1 you may be skip first or last postion so always make sure to use eual opertor and other wise +1;


//     *
//    ***
//   *****
//  *******
// *********
//  *******
//   *****
//    ***
//     *