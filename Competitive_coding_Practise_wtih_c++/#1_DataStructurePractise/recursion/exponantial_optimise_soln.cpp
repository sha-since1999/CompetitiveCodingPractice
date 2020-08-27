#include<iostream>
double expo( int x, int n )
{
    static double  s=1;
    if( n==0 )return s;
    s=1+(x/n)*s;
    return expo(x,n-1);

}
int main()  
{
    std::cout <<"ans =" <<expo(1,5)<<std::endl;   
    
    return 0;

}
