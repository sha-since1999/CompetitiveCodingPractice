#include<bits/stdc++.h>
using namespace std;
int countSetBits(int x)
{
    int cnt=0;
    while (x)
    {
        cnt+=(x&1);
        x=x>>1;
    }
    return cnt;
}
int countSetBitsFast(int n)
{
    int  cnt=0;
    while (n) n&=(n-1), cnt++;

    return cnt;
}
int removeLastBit(int n)
{
    return n?n&(n-1):0;
}
void clear_ith_bit(int &n, int i)
{
    n=n&(~(1<<i));

}

void swapUsingXor(int &a, int &b)// swap by reference
{

    a=a^b;
    b=a^b;
    a=a^b;
}

// void swapUsingXor(int *a, int *b) // swap by using address pointer  
// {
//     *a=*a^*b;
//    *b=*a^*b;
//    *a=*a^*b;
// }
bool extract_ith_Bit(int n, int i)
{
    return n&(1<<i);
}
void set_ith_bit(int &n, int i)
{
    n=n|(1<<i);
}

bool isPowerOfTwo(int n)
{
    return n&(n-1)? 0:1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    // cout<<countSetBits(12)<<endl;
    // cout<<removeLastBit(13)<<endl;


    // int a=8, b=9;
    // swapUsingXor(a, b); // swap using reference
    // // swapUsingXor(&a,&b);// swap using address pointer
    // cout<<a<<" "<<b<<endl;

    // cout<<extract_ith_Bit(101, 1)<<endl;

    // int x=12;

    // // set_ith_bit(x, 1);
    // clear_ith_bit(x, 3);
    // cout<<x<<endl;

    // cout<<isPowerOfTwo(8)<<endl;
    // cout<<isPowerOfTwo(9)<<endl;


    // cout<<countSetBitsFast(23)<<endl;

    return 0;
}

// here everything is well tested  by me all okk