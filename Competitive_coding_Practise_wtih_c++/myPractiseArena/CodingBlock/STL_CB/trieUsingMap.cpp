#include <bits/stdc++.h>
using namespace std;
struct trienode
{
    char ch;
    unordered_map<char, trienode *> child;
    int wc;
};

class trie
{
private:
    trienode *root;

public:
    trie()
    {
        root = getnode(' ');
    }
    trienode *getnode(char c)
    {
        trienode *newnode = new trienode;
        newnode->wc = 0;
        newnode->ch = c;
        return newnode;
    }
    void insert(string s)
    {
        trienode *curr = root;
        for (char c : s)
        {
            if (curr->child.count(c) == 0)
                curr->child[c] = getnode(c);
            curr = curr->child[c];
            curr->wc++;
        }
    }
    int find(string s)
    {
        trienode *curr = root;
        for (char c : s)
        {
            if (curr->child.count(c))
                curr = curr->child[c];
        }
        return curr->wc;
    }
};
int main()
{
    trie t;
    string s = "ram is the good boy bames";
    char *ptr = strtok((char *)s.c_str(), " ");
    while (ptr != NULL)
    {
        t.insert(ptr);
        ptr = strtok(NULL, " ");
    }
    cout << t.find("ram") << endl;
    cout << t.find("is") << endl;
    cout << t.find("b") << endl;

    return 0;
}
