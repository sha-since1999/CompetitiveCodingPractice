#include <bits/stdc++.h>
#include "input.h"
using namespace std;
string word[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void spellIt(int n)
{
    if (n > 0)
    {
        int x = n % 10;
        n /= 10;
        spellIt(n);
        cout << word[x] << " ";
    }
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 324268;
    spellIt(n);

    return 0;
}