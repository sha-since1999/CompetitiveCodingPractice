#include <iostream>
#include <cstring>
#include "input.h"
using namespace std;
//  create own strtok function.
char *mystrtok(char *s, char delim)
{
    static char *input = NULL;
    if (s != NULL)
        input = s; //manage the first call.
    if (input == NULL)
        return NULL; //manage the last call.
    char *output = new char[strlen(input) + 1];
    int i = 0;
    for (; i < strlen(input); i++)
    {
        if (input[i] != delim)
            output[i] = input[i];
        else
        {
            output[i] = '\0';
            input = input + i + 1;
            return output;
        }
    }
    // corner cases
    output[i] = '\0';
    input = NULL;
    return output;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char s[1000];
    cin.getline(s, 1000);

    // Using inbuilt function----------_>
    // char *ptr = strtok(s, " ");
    // cout << ptr << endl;
    // while (ptr != NULL)
    // {
    //     ptr = strtok(NULL, " ");
    //     cout << ptr << endl;
    // }

    // by my own function---------->
    // char *ptr = mystrtok(s, ' ');
    // cout << ptr << endl;
    // while (ptr != NULL)
    // {
    //     ptr = mystrtok(NULL, ' ');
    //     cout << ptr << endl;
    // }



    // string ptr = strtok(s, " ");
    // cout << ptr << endl;
    // while (!ptr.empty())
    // {
    //     ptr = strtok(NULL, " ");
    //     cout << ptr << endl;
    // }


    return 0;
}