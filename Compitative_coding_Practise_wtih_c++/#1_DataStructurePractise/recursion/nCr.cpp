#include<iostream>
using namespace std;
int fact(int n)             //for normal function
{
    if (n==0) return 1;
    else  return n*fact(n-1);
}
int simple_nCr(int n ,int r)
{
    if (n==0) return 1;
    else return fact(n) /(fact(r) * fact(n-r));
}


 int nCr(int n,int r)   // optimise function
 {
     if (r==0|| n==r)    return 1;
     else
     {
         return nCr(n-1,r-1)+nCr(n-1,r);
     }
     
 }
int main()
{ cout<< "nCr="<< nCr(3,2)<< endl;/// using optimise soln
cout<< "nCr="<< simple_nCr(5,2)<< endl;// using simple method normal recursoio


    return 0;

}