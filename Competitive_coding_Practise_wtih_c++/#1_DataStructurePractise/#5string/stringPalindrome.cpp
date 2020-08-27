#include <bits/stdc++.h>
using namespace std;
void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}
bool isPalimdrome(string s)   // easy solution  using c++ stl
{
    int i=0, j= s.size()-1;
    while (i<j)
        if (s[i++]!=s[j--])return false;
    return true;
}
int main()
{
    string str2 = "abcdcba";
    string str1 = str2;
    int i, j;
    int length = str2.size();
    for (int i = 0, j = length - 1; i < j; i++, j--) // reverse string by using basic concept 
        swap(str1[i], str1[length - i - 1]);
    cout << str1 << endl;
    cout << str2 << endl;
    for (i = 0, j = 0; str1[i] != '\0', str2[j] != '\0'; i++, j++)
    {
        if (str2[j] != str1[i])
            break;
    }
    if (str2[j] == str1[i])
        cout << "both string ara equal and palindrome" << endl;
    else if (str2[j] > str1[i])
        cout << str2 << "  is greater" << endl;
    else
        cout << str1 << "  is greater" << endl;



    // # method using simple than basic
   //   just this function is sufficient to check  (#simple easy solution)
    cout<<isPalimdrome("abcdcba");


    return 0;
}