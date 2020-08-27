#include<bits/stdc++.h>
using namespace std;
int n=4;
int dist [10][10]={
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};
int VISITED_ALL=(1<<n)-1;
int tsp(int pos,int mask)
{
    if(mask==VISITED_ALL) return dist[pos][0];
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
        if((mask&(1<<i))==0)
        {
        int  new_ans =dist[pos][i]+tsp(i,mask|(1<<i));
        ans=min(new_ans,ans);
        }
    return  ans;
}
 int main()
 {
cout<<"Travelling salesman distance is" <<tsp(0,1)<<endl;
     return 0;
 }