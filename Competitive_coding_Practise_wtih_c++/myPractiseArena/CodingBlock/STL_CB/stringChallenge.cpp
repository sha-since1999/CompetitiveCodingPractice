#include <bits/stdc++.h>

using namespace std;
vector<pair<string, string>> mp;
void createMap(string s, int key)
{
    string tmp = s;
    char *ptr = strtok((char *)s.c_str(), " ");
    while (key > 1)
    {
        ptr = strtok(NULL, " ");
        key--;
    }
    mp.emplace_back(tmp, ptr);
}
bool NumericComparator(pair<string, string> a, pair<string, string> b)
{
    return stoi(a.second) < stoi(b.second);
}
bool LexographicComparator(pair<string, string> a, pair<string, string> b)
{
    return a.second < b.second;
}
int main()
{
    int n;
    cin >> n;
    cin.get();
    string s[100];
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }
    int key;
    string order, reversal;
    cin >> key >> reversal >> order;
    for (int i = 0; i < n; i++)
        createMap(s[i], key);

    if (order == "lexographic")
        sort(mp.begin(), mp.end(), LexographicComparator);
    else
        sort(mp.begin(), mp.end(), NumericComparator);
    if (reversal == "true")
        reverse(mp.begin(), mp.end());

    for (auto m : mp)
    {
        cout << m.first << endl;
    }
    return 0;
}

// 3
// 92 022
// 82 12
// 77 13
// 2 false numeric