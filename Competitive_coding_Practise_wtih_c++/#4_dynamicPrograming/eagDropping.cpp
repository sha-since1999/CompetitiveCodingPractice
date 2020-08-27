#include<bits/stdc++.h>
using namespace std;
static int t[50][50];
int solve(int e,int f)
{
if(f==0||f==1||e==1) return f;
if(t[e][f]!=-1)
 return t[e][f];
int mn=INT_MAX;
for(int k=2;k<=f;k++)
{
    int temp=1+max(solve(e-1,k-1),solve(e,f-k));
    if(mn>temp)
    mn=temp;
}
return t[e][f]=mn;
}
int Osolve(int e,int f)
{
if(f==0||f==1||e==1) return f;
if(t[e][f]!=-1) return t[e][f];
int low,high;
int mn=INT_MAX;
for(int k=2;k<=f;k++)
{
if(t[e-1][k-1]!=-1) low=t[e-1][k-1];
else low=Osolve(e-1,k-1);
if(t[e][f-k]!=-1) high =t[e][f-k];
else high=Osolve(e,f-k);
int temp=1+max(low,high);
mn=min(mn,temp);
}
return t[e][f]=mn;
}
int main()
{   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(t,-1,sizeof(t));
    cout<<Osolve(3,6)<<endl;;
    return 0;
}