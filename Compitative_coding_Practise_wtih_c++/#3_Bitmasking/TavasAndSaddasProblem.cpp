#include<bits/stdc++.h>
using namespace std;
//sea problem statement below//
int  findPosition(string s)
{
    int digitLength=s.size()-1;
    int cnt=0;
    for (int position=0;position<s.size();position++)
    {
        if (s[digitLength-position] =='7')
            cnt+=2*(1<<position);
        else
            cnt+=1*(1<<position);
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string x = "1";
    cout<<findPosition(x)<<endl;



    return 0;
}

// problem statement: find the position of the given no in  series of magical no using 7 and 4 only;
// ex: 4,7,44,47,74,77,444,447,474,477,744,747,774,777,......

// this code Forces famous problem on bitmasking u can find there.