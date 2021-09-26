#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> mp;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data) : data(data)
    {
        left = right = NULL;
    }
};
void printVertical(node *root, int pos)
{
    if (root == NULL)
        return;
    mp[pos].push_back(root->data);
    printVertical(root->left, pos - 1);
    printVertical(root->right, pos + 1);
}
void printBinary(node *root)
{
    if (root)
    {
        printBinary(root->left);
        cout << root->data << " ";
        printBinary(root->right);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    node *root;
    root = new node(6);
    root->left = new node(4);
    root->right = new node(5);

    root->left->left = new node(7);
    root->left->left->left = new node(12);
    root->left->left->right = new node(13);

    root->left->right = new node(24);
    root->left->right->left = new node(22);
    root->left->right->right = new node(25);

    root->right->right = new node(45);
    root->right->left = new node(40);
    root->right->right->right = new node(49);
    root->right->right->left = new node(42);
    root->right->left->right = new node(32);
    root->right->left->left = new node(34);

    // printBinary(root); //inorder_print
    printVertical(root, 0);
    for (auto m : mp)
    {
        cout << m.first << " --->";
        for (int x : m.second)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}