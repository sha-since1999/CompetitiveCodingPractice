#include <iostream>
#include <cstring>
using namespace std;
long count_pair(string S)
{

    long pair_count = 0;
    long i = 0;
    while (S[i] != '\0'&& i<S.length()-1)
    {

        if (S[i] != S[i+1] )
        {
            i = i + 2;
            pair_count++;
        }
        else
            i++;
    }

    return pair_count;
}
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string S;
        cin >> S;
        cout << count_pair(S) << endl;
    }

    return 0;
}