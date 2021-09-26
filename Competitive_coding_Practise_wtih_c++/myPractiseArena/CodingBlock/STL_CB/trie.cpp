#include <bits/stdc++.h>
using namespace std;
class trienode
{
public:
    char ch;
    trienode *child[26];
    int wc;

    trienode(char c) : ch(c)
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        wc = 0;
    }
};

trienode *root = new trienode(' ');

void insert(string s)
{
    trienode *curr = root;
    for (int i = 0; s[i]; i++)
    {
        if (curr->child[s[i] - 'a'] == NULL)
            curr->child[s[i] - 'a'] = new trienode(s[i]);
        curr = curr->child[s[i] - 'a'];
        curr->wc++;
    }
}
int check(string s)
{
    trienode *curr = root;
    for (int i = 0; s[i]; i++)
    {
        if (curr->child[s[i] - 'a'])
            curr = curr->child[s[i] - 'a'];
    }
    return curr->wc;
}
int main()
{
  
    string s = "ram is the good boy bames";
    char *ptr = strtok((char *)s.c_str(), " ");
    while (ptr != NULL)
    {
        insert(ptr);
        ptr = strtok(NULL, " ");
    }
    cout << check("ram") << endl;
    cout << check("is") << endl;
    cout << check("b") << endl;

    return 0;
}
