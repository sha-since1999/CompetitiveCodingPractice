#include <bits/stdc++.h>
using namespace std;
char res[5];
int k = 0;
bool a[5] = {false};

vector<string> digit;
void perm_first_method(string s, int k)
{
    if (s[k] == '\0')
    {
        res[k] = '\0';
        cout << res << endl;
    }
    else
        for (int i = 0; i < s.size(); i++)
        {
            if (!a[i])
            {
                res[k] = s[i];
                a[i] = true;
                perm_first_method(s, k + 1);
                a[i] = false;
            }
        }
}


void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void perm_second_method(string s, int l, int h)
{
    if (l == h)
    {
        cout << s << endl;
        digit.push_back(s);
    }

    else
    {
        for (int i = l; i <= h; i++)
        {
            swap(&s[i], &s[l]);
            perm_second_method(s, l + 1, h);
            swap(&s[i], &s[l]);
        }
    }
}
// try to permute the digit using this method
void permuteDigit(int D)
{
    int sum = 0;
    string s = to_string(D);
    perm_second_method(s, 0, s.size() - 1);
    stringstream ss;
    for (string str : digit)
    {
        ss << str;
        ss >> D;
        cout << D << endl;
        sum += D;
    }
    cout << "sum of permutated numbers: " << sum << endl;
}

int main()
{
    // string s = "ABC";
    // perm_first_method(s, 0);
    // cout << "using second method" << endl;
    // perm_second_method(s, 0, s.size() - 1);
    cout << "<----Digit permutation---->" << endl;
    permuteDigit(234);
    return 0;
}