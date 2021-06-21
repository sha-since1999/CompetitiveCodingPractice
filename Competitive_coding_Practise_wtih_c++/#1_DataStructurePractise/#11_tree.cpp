#include <iostream>
#include "treeNeed.h"
// #include "sahu.h"
using namespace std;
class tree
{
private:
public:
    node *root;

    tree()
    {
        root = NULL;
    }
    int insert(int key);
    void create(void);
    void IpreOrder();
    void IinOreder();
    void IpostOrder();
    void rIPreOrder(node *);
    void rIInOreder(node *);
    void rIPostOrder(node *);
    void levelOrder(node *);
    int count(node *);
    int height(node *);
    int count_nodes(node *);
    int count_terminal(node *);
    int sum_of_key(node *);
};
void tree::create()
{
    node *p = root, *t;
    int x;
    t = new node;
    queue Q(10);
    cout << "\nEnter the Root Element: ";
    cin >> t->data;
    t->lchild = t->rchild = NULL;
    if (root == NULL)
        root = t;
    Q.enqueue(root);
    while (!Q.isEmpty())
    {
        p = Q.dequeue();
        cout << "\nEnter the left child of " << p->data << ":  ";
        cin >> x;
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            Q.enqueue(p->lchild);
        }
        cout << "\nEnter the Right child of " << p->data << ":  ";
        cin >> x;
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            Q.enqueue(p->rchild);
        }
    }
}
void tree::IpreOrder()
{
    node *p = root;
    stack stk(100);
    while (p || !stk.isEmpty())
    {
        if (p)
        {
            cout << p->data << " ";
            stk.push(p);
            p = p->lchild;
        }
        else
        {

            p = stk.pop();
            p = p->rchild;
        }
    }
}
void tree::IinOreder()
{
    node *p = root;
    stack stk(100);
    while (p || !stk.isEmpty())
    {
        if (p)
        {
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}
// void tree::IpostOrder()
// {
//     node *p = root, *temp;
//     stack stk(100);
//     while (p || !stk.isEmpty())
//     {
//         if (p)
//         {
//             stk.push(p);
//             p = p->lchild;
//         }
//         else
//         {
//             temp = stk.pop();
//             if (temp > 0)
//             {
//                 stk.push(-temp);
//                 p = ((node *)temp)->rchild;
//             }
//             else
//             {
//                 cout << ((node *)temp)->data << " ";
//                 p = NULL;
//             }
//         }
//     }
// }
void tree::rIPreOrder(node *p)
{
    if (p)
    {
        cout << p->data << " ";
        rIPreOrder(p->lchild);
        rIPreOrder(p->rchild);
    }
}
void tree::rIInOreder(node *p)
{
    if (p)
    {
        rIInOreder(p->lchild);
        cout << p->data << " ";
        rIInOreder(p->rchild);
    }
}
void tree::rIPostOrder(node *p)
{

    if (p)
    {
        rIPostOrder(p->lchild);
        rIPostOrder(p->rchild);
        cout << p->data << " ";
    }
}
void tree::levelOrder(node *p)
{
    queue Q(100);
    cout << p->data << " ";
    Q.enqueue(p);
    while (!Q.isEmpty())
    {
        p = Q.dequeue();
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            Q.enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            Q.enqueue(p->lchild);
        }
    }
}
int tree::count_nodes(node *p)
{
    int x, y;
    if (p)
    {
        x = count_nodes(p->lchild);
        y = count_nodes(p->rchild);
        return x + y + 1;
    }
    return 0;
}
int tree::count(node *p)
{
    if (p)
    {
        return count(p->lchild) + count(p->rchild) + 1;
    }
    return 0;
}
int tree::height(node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int tree::sum_of_key(node *p)
{
    int x, y;
    if (p)
    {
        x = sum_of_key(p->lchild);
        y = sum_of_key(p->rchild);
        return x + y + p->data;
    }
    return 0;
}
// int tree::count_terminal(node *p)
// {
//     if (!p)
//         return 0;
//     if (!p->lchild && p->rchild)
//     {
//         return count_terminal(p->lchild) + count_terminal(p->rchild) + 1;
//     }
//     return count_terminal(p->lchild) + count_terminal(p->rchild);
// } //not corrrect

int main()
{
    tree t;
    t.create();
    // t.IpreOrder();
    // t.IinOreder();
    //t.IpostOrder(); ////some problem with this function
    // t.rIPreOrder(t.root);
    // t.rIInOreder(t.root);
    // t.rIPostOrder(t.root);
    t.levelOrder(t.root);
    cout << t.count_nodes(t.root) << endl;
    cout << t.sum_of_key(t.root) << endl;
    cout << t.count(t.root) << endl;
    cout << t.height(t.root) << endl;

    // cout << t.count_terminal(t.root);
    return 0;
}