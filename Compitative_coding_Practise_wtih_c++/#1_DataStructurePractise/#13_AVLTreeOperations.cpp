#include <bits/stdc++.h>

using namespace std;
class node
{
public:
    node *lchild;
    int data;
    int height;
    node *rchild;

} * root;

class Avl
{
public:
    Avl()
    {
        root = NULL;
    }
    node *newnode(int data)
    {
        node *t = new node;
        t->rchild = t->lchild = NULL;
        t->height = 1;
        t->data = data;
        return t;
    }
    node *insert(node *, int);
    node *delete_node(node *, int);
    int nodeHeight(node *);
    int balanceFactor(node *);
    node *LLrotation(node *);
    node *LRrotation(node *);
    node *RRrotation(node *);
    node *RLrotation(node *);
    node *Inpre(node *);
    node *InSucc(node *);
    void InOrder(node *);
};
node *Avl::insert(node *p, int data)
{

    if (!p)
    {
        p = newnode(data);
        return p;
    }
    if (p->data > data)
        p->lchild = insert(p->lchild, data);
    else if (p->data < data)
        p->rchild = insert(p->rchild, data);
    p->height = nodeHeight(p);
    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LLrotation(p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LRrotation(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return RRrotation(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return RLrotation(p);

    return p;
}
int Avl::nodeHeight(node *p)
{
    int hl, hr;
    if (!p)
        return 0;

    hl = nodeHeight(p->lchild);
    hr = nodeHeight(p->rchild);

    return hl > hr ? hl + 1 : hr + 1;
}
int Avl::balanceFactor(node *p)
{
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    return hl - hr;
}
node *Avl::LLrotation(node *p)
{
    node *pl = p->lchild;
    node *plr = pl->rchild;
    p->lchild = plr;
    pl->rchild = p;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);
    if (root == p)
        root = pl;
    return pl;
}
node *Avl::LRrotation(node *p)
{
    node *pl = p->lchild;
    node *plr = pl->rchild;

    p->lchild = plr->rchild;
    pl->rchild = plr->lchild;
    plr->rchild = p;
    plr->lchild = pl;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);
    plr->height = nodeHeight(plr);
    if (root == p)
        root = plr;
    return plr;
}
node *Avl::RRrotation(node *p)
{
    node *pr = p->rchild;
    node *prl = pr->lchild;
    p->rchild = prl;
    pr->lchild = p;
    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);
    if (root = p)
        root = pr;
    return pr;
}
node *Avl::RLrotation(node *p)
{
    node *pr = p->rchild;
    node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;
    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);
    prl->height = nodeHeight(prl);
    if (root = p)
        root = prl;
    return prl;
}
node *Avl::Inpre(node *p)
{
    while (p && p->rchild)
    {
        p = p->rchild;
    }
    return p;
}
node *Avl::InSucc(node *p)
{
    while (p && p->lchild)
    {
        p = p->lchild;
    }
    return p;
}
void Avl::InOrder(node *p)
{
    if (p)
    {

        InOrder(p->lchild);
        cout << p->data << " " << endl;
        InOrder(p->rchild);
    }
    return;
}
node *Avl::delete_node(node *p, int data)
{
    node *q;
    if (!p)
        return NULL;
    if (!p->lchild && !p->rchild && p->data == data)
    {
        delete[] p;
        return NULL;
    }
    if (data < p->data)
        p->lchild = delete_node(p->lchild, data);
    else if (data > p->data)
        p->rchild = delete_node(p->rchild, data);
    else if (data == p->data)
    {
        if (nodeHeight(p->lchild) > nodeHeight(p->rchild))
        {
            q = Inpre(p->lchild);
            p->data = q->data;
            p->lchild = delete_node(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = delete_node(p->rchild, q->data);
        }
    }

    p->height = nodeHeight(p);
    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LLrotation(p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LRrotation(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return RRrotation(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return RLrotation(p);
    return p;
}
int main()
{

    Avl Av;
    root = Av.insert(root, 1);
    root = Av.insert(root, 45);
    root = Av.insert(root, 4);
    root = Av.insert(root, 12);

    root = Av.insert(root, 13);
    root = Av.insert(root, 4);
    root = Av.delete_node(root, 4);
    root = Av.delete_node(root, 45);
    root = Av.delete_node(root, 412);

    root = Av.delete_node(root, 1);

    // root = Av.delete_node(root, 12);
    // root = Av.delete_node(root, 1);

    Av.InOrder(root);
    return 0;
}

// every thing is okkk and well tested