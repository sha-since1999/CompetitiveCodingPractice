#include<iostream>

double expo(int x,int n)
{ static double p=1,f=1;
double r;
	if (n==0){ return 1;}
	else {
	    r=expo(x,n-1);
		p*=x;
		f*=n;
		return r+p/f ;

	}
}
 int main()
 {

 std:: cout<< "exponantial ="<< expo(4,10)<<std::endl; 
return 0;
}