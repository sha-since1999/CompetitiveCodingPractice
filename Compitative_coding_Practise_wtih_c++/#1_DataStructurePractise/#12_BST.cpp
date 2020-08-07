#include <iostream>
#include "treeNeed.h"
// #include "sahu.h"
using namespace std;

class BST
{
private:
public:
    node *root;
    BST()
    {
        root = NULL;
    }

    int height(node *);
    int count(node *);
    void insert(int key);
    void traverse(node *);
    void createPre(int *, int);
    void createPost(int *, int);
    void createIn(int *, int);
    node *search(int key);
    node *Rsearch(node *, int);
    node *Inpre(node *);
    node *Insucc(node *);
    node *delete_node(node *, int);
};
void BST::insert(int key)
{
    node *t, *r, *p = root;
    while (p)
    {
        r = p;
        if (key == p->data)
            return; //bec no duplicacy allowed
        else if (key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    t = new node;
    t->data = key;
    t->lchild = t->rchild = NULL;
    if (root == NULL)
    {
        root = t;
        return;
    }
    if (r->data < t->data)
        r->rchild = t;
    else
        r->lchild = t;
}
node *BST::Rsearch(node *p, int key)
{
    if (!p)
        return NULL;
    if (key == p->data)
        return p;
    else if (key > p->data)
        return Rsearch(p->rchild, key);
    else
        return Rsearch(p->lchild, key);
}
node *BST::search(int key)
{
    node *p = root;
    while (p)
    {
        if (p->data == key)
            return p;
        else if (key > p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return NULL;
}
void BST::traverse(node *p)
{

    if (p)
    {
        traverse(p->lchild);
        cout << p->data << " ";
        traverse(p->rchild);
    }
}
int BST::height(node *p)
{

    int x, y;
    if (!p)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
}
int BST::count(node *p)
{
    if (p)
    {
        return count(p->lchild) + count(p->rchild) + 1;
    }
    return 0;
}
node *BST::Inpre(node *p) //in this case you have to provide the next element whose precessor is required
{

    while (p && p->rchild)
    {
        p = p->rchild;
    }
    return p;
}
node *BST::Insucc(node *p) //this also tru in this case you have to pass root element whose successor is required
{
    while (p && p->lchild)
    {
        p = p->lchild;
    }
    return p;
}
node *BST::delete_node(node *p, int key)
{
    node *q;
    if (!p)
        return NULL;
    if (!p->lchild && !p->rchild && p->data == key)
    {
        delete[] p;
        return NULL;
    }
    if (key < p->data)
        p->lchild = delete_node(p->lchild, key);
    else if (key > p->data)
        p->rchild = delete_node(p->rchild, key);
    else if (key == p->data)
    {
        if (height(p->lchild) > height(p->rchild))
        {
            q = Inpre(p->lchild);
            p->data = q->data;
            p->lchild = delete_node(p->lchild, q->data);
        }
        else
        {
            q = Insucc(p->rchild);
            p->data = q->data;
            p->rchild = delete_node(p->rchild, q->data);
        }
    }
    return p;
}
void BST::createPre(int *pre, int n)
{
    node *t, *p;
    int i = 0;
    stack stk(100);
    t = new node;
    t->lchild = t->rchild = NULL;
    t->data = pre[i++];
    p = root = t;

    while (i < n)
    {

        if (pre[i] < p->data)
        {

            t = new node;
            t->data = pre[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        else
        {
            // this step is necessory to insert right element in the stack;
            if (stk.isEmpty())
            {
                stk.push(infy_node_pointer());
            }
            // cout << p->data << "-->" << (stk.stackTop())->data << endl;
            if (pre[i] > p->data && (stk.stackTop())->data > pre[i])
            {
                t = new node;
                t->data = pre[i++];
                t->rchild = t->lchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = stk.pop();
            }
        }
    }
}
void BST::createPost(int *post, int n)
{
    node *t, *p;

    int i = n - 1;
    stack stk(100);
    t = new node;
    t->lchild = t->rchild = NULL;
    t->data = post[i--];
    p = root = t;

    while (i > -1)
    {

        if (post[i] > p->data)
        {

            t = new node;
            t->data = post[i--];
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            stk.push(p);
            p = t;
        }
        else
        { //this step is necessory to insert left element in the stack;
            if (stk.isEmpty())
            {
                stk.push(minus_infy_node_pointer());
            }
            // cout << p->data << "-->" << (stk.stackTop())->data << endl;
            // cout << (stk.stackTop())->data << endl;
            if (stk.isEmpty())
            {
                stk.push(minus_infy_node_pointer());
            }
            if (post[i] < p->data && post[i] > (stk.stackTop())->data)
            {
                t = new node;
                t->data = post[i--];
                t->rchild = t->lchild = NULL;
                p->lchild = t;
                p = t;
            }
            else
            {
                p = stk.pop();
            }
        }
    }
}
// void BST::createIn(int *ino, int n)
// {
//     node *t, *p;
//     int i = n / 2;
//     int j = i;
//     queue Q(100);
//     t = new node;
//     t->data = ino[i];
//     t->lchild = t->rchild = NULL;
//     p = root = t;
//     Q.enqueue(root);
//     while (i < n && j > 0)
//     {
//         p = Q.dequeue();
//         if (ino[--j] < p->data && (ino[++i] > p->data))
//         {
//             cout << p->data << endl;
//             t = new node;
//             t->data = ino[j];
//             t->lchild = t->rchild = NULL;
//             p->lchild = t;
//             Q.enqueue(p->lchild);
//             t = new node;
//             t->data = ino[i];
//             t->lchild = t->rchild = NULL;
//             p->rchild = t;
//             Q.enqueue(p->rchild);
//         }
//     }
// }// this very dificult  to impliment no to proper implementation on net also

int main()
{
    BST B;
    B.insert(5);
    B.insert(3);
    B.insert(8);
    B.insert(9);
    B.insert(2);
    B.insert(1);
    int pre[7] = {10, 5, 1, 7, 40, 50};
    int post[7] = {3, 6, 5, 15, 25, 20, 10};
    int ino[7] = {3, 5, 7, 9, 10, 12, 14};

    // B.createPre(pre, 6);
    // B.createPost(post, 7);
    // B.createIn(ino, 7);
    // B.delete_node(B.root, 232);
    // B.delete_node(B.root, 89);
    // B.delete_node(B.root, 8);
    // B.delete_node(B.root, 1);
    // B.delete_node(B.root, 1);
    // B.delete_node(B.root, 1);
    // B.delete_node(B.root, 1);
    // B.delete_node(B.root, 2);
    // B.delete_node(B.root, 2);
    // B.delete_node(B.root, 8);
    // B.delete_node(B.root, 8);
    // cout << B.count(B.root) << endl;
    B.traverse(B.root);
    return 0;
}

// this is welll tested by me only inorder creation is not properly implemented ;