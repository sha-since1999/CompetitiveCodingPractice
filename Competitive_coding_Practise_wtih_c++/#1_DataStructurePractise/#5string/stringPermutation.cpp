#include<bits/stdc++.h>
using namespace std;
bool a[10]={ 0 };
char res[10];
int k=0;
void stringPermutation(string s, int k)
{
    if (s[k]=='\0')
        res[k]='\0', cout<<res<<" ";
    else

        for (int i=0;s[i]!='\0';i++)
        {
            if (a[i]!=1)
            {
                res[k]=s[i];
                a[i]=1;
                stringPermutation(s, k+1);
                a[i]=0;
            }

        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stringPermutation("abc", 0);

    return 0;
}