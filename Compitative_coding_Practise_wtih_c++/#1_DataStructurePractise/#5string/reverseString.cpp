#include <bits/stdc++.h>
using namespace std;

int main()
{
    // string str = "rohit";
    string str;
    getline(cin, str);

    int j, i;
    for (j = 0; str[j] != '\0'; j++)
        ;
    j--;

    //simple method to reverse the string
    // char rstr[j];
    // for (i = 0; j >= 0; i++, j--)
    // {
    //     rstr[i] = str[j];
    // }
    // rstr[i] = '\0';
    // cout << rstr << endl;

    // //string reverese using swap optimise way
    for (int i = 0; j > i; i++, j--)
    {
        int temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    cout << str << endl;
    return 0;
}