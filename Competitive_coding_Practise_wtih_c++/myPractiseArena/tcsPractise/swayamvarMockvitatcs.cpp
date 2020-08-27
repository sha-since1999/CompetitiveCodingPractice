#include <bits/stdc++.h>
#include "sahu.h"
using namespace std;
typedef long long ll;
int N;
int unmatchedPair(string g, string b)
{
    vector<int> anagramMark(26, 0);
    for (int i = 0; g[i] != '\0'; i++)
        anagramMark[g[i] - 97]++;
    for (int j = 0; b[j] != '\0'; j++)
    {
        if (!anagramMark[b[j] - 97])
            return N - j;
        anagramMark[b[j] - 97]--;
    }
    return 0;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {

        string b, g;
        cin >> N;
        cin >> b >> g;
        cout << unmatchedPair(g, b) << endl;
    }
    return 0;
}

// 2
// 4
// rrmm mrmr
// 4
// rmrm mmmr

// ans 0  2