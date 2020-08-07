#include <iostream>
using namespace std;
int main()
{
    int hast_table_of_alphabets[26] = {0};
    string S;
    cin >> S;
    cout << S.c_str();
    // for (int i = 0; i < 26; i++)
    // {
    //     hast_table_of_alphabets[i] = 0;
    // }
    for (int i = 0; S[i] != '\0'; i++)
    {

        hast_table_of_alphabets[S[i] - 97] = 1;
    }
    /*print hast table for checking*/

    // for (int i = 0; i < 26; i++)
    // {
    //     cout << hast_table_of_alphabets[i];
    // }

    cout << "Enter the test case no.:" << endl;

    int T;
    cin >> T;
    while (T--)
    {
        cin >> S;
        bool flag = true;
        for (int i = 0; S[i] != '\0'; i++)
        {
            if (!hast_table_of_alphabets[S[i] - 97])
            {
                flag = false;
                cout << "NO" << endl;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
    }

    return 0;
}