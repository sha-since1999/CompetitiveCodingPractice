#include<bits/stdc++.h>
using namespace std;
int main(){
       int n;cin>> n;
       for( int i=0;i<n;i++){
           for(int j=0;j<n-1-i;j++)cout<<"  ";
           for(int j=0;j<=i;j++){
            if(j==i or j==0 or i==n-1) cout<<"* "; else cout<<"  ";
           }
           cout<<endl;
       }


     return 0;
}



// * 
// * * 
// *   * 
// *     * 
// * * * * * 


//  note : for this type of pattern always concern about sapce may be you have to use a double space ;