#include<bits/stdc++.h>
using namespace std;
 
int main()
{   ios::sync_with_stdio(false);
     cin.tie(nullptr);
     int n;cin>>n;
     for (int j,i = 1; i <= n;i++){
          for(j=1;j<i;j++)cout<<" ";
          for(j=1;j<2*(n-i+1);j++)cout<<"*";
          cout<<endl;
     }
   return 0;
}



// *********
//  *******
//   *****
//    ***
//     *