#include <bits/stdc++.h>
using namespace std;
bool is_anagram(string b, string g)
{
    vector<int> anagramMark(26, 0);
    for (int i = 0; b[i] != '\0'; i++)
    {
        anagramMark[b[i] - 97]++;
    }
    int j;
    for (j = 0; g[j] != '\0'; j++)
    {
        anagramMark[g[j] - 97]--;
        if (anagramMark[g[j] - 97] < 0)
        {
            return false;
        }
    }
    if (g[j] == '\0')
        return true;

    return false;
}
int main()
{
    string str1 = "observe";
    string str2 = "verbose";
    if (is_anagram(str1, str2))
        cout << "these are an Anagram string" << endl;
    else
        cout << "Not an anagram string" << endl;

    return 0;
}
