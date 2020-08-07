#include <iostream>
using namespace std;
long eval_revenue(long * A,int N,int K)
{
    int i;
    long sum=0;
    for(i=0;i<N;i++)
    {
        if(A[i]>K)
        sum+=A[i]-K;
    }
    return sum;
}

int main() {
    int T;
    long K;
    long N;

   std:: cin>>T;
    
    while(T--)
    {
        std::cin >>N>>K;
        long price_list[N],i;
           for(i=0;i<N;i++)
        {
            std::cin>>price_list[i];
            
        }
       std::cout<<eval_revenue(price_list,N,K)<<endl;
    }

	return 0;
}
