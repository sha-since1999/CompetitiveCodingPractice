#include<iostream>
using namespace std;
int main()
{
//    int p[4];
   int *p=new int[4];



    cin>>p[0]>>p[1]>>p[2]>>p[3];
    cout<<p[0]<<p[1]<<p[2]<<p[3];
    delete []p;
    return 0;
}