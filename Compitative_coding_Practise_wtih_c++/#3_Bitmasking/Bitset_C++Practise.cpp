#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*<<<-----integer to bitset vice-versa*/
    // bitset<5> b(8);
    // cout<<b<<endl;// 01000
    // cout<<(int)b.to_ulong()<<endl; // 8

    /* <<---string to bitset vice - versa*/
    // string str= "101101011010";
    // bitset<12>brr(str);
    // cout<<brr<<endl;
    // cout<<brr[0]<<endl;
    // string new_str=brr.to_string();
    // cout<<new_str<<endl;

    /*<<<------ count no of ones*/
    // cout<<brr.count()<<endl;

    /*<<<------ basic Operation*/
    // bitset<4>a(string("1010"));
    // bitset<4>b(string("0101"));
    // cout<<(a&b)<<endl;
    // cout<<(a|b)<<endl;
    // cout<<(a^b)<<endl;
    // cout<<a<<endl;
    // cout<<(a<<1)<<endl;
    // cout<<(a>>1)<<endl;

    /*<<-----iSTRINGSTREAM*/
    // string str="10101010110";
    // stringstream ss(str);
    // bitset<3> a;
    // bitset<8> b;
    // ss>>a;cout<<a<<endl;
    // ss>>b;cout<<b<<endl;

    /*<<<------check if any bit is set*/
    // bitset<4>a(string("1010"));
    // bitset<4>b(string("0000"));
    // cout<<a.any()<<endl;
    // cout<<b.any()<<endl;

    /*<<<----check if None of bits are set*/
    // cout<<a.none()<<endl;
    // cout<<b.none()<<endl;

    /*<<<<<---flip all or any particular bit*/
    // bitset<4> a(string("1010"));
    // cout<<a.flip(1)<<endl;
    // cout<<a<<endl;
    // cout<<a.flip()<<endl;

    /* <<<<-----reset all or any particular bit*/
    // bitset<4> a(string("1010"));
    // cout<<a.reset(1)<<endl;
    // cout<<a.reset()<<endl;

    /* <<<<-----set all or any particular bit*/
    // bitset<4> a(string("1010"));
    // cout<<a.set(1)<<endl;
    // cout<<a.set()<<endl;

    return 0;
}
