#include<bits/stdc++.h>
using namespace std;
int main(){
    
 int n ;cin>>n;
 for(int j,i=0;i<n;i++){
     for(j=0;j<=i;j++)cout<<"*";
     cout<<endl;
 }
 for(int j,i=0;i<n-1;i++){
     for(j=0;j<n-i-1;j++)cout<<"*";
     cout<<endl;
 }
    return 0;
}

// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *