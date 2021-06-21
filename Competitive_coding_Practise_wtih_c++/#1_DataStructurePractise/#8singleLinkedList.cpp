#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;

} *first = NULL, *second = NULL;

struct node *create(struct node *first, int a[], int n)
{
    struct node *temp, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
    return first;
}

node *search(struct node *p, int x)
{
    //  while(p->next)
    //  {
    //      if(p->data==x)
    //          return p;
    //      p = p->next;

    /*using recursion*/
    if (!p)
        return 0;
    if (p->data == x)
        return p;
    else
        search(p->next, x);

    return 0;
}

int min(struct node *p)
{
    int mn;
    if (!p)
        return INT32_MAX;
    else
    {
        mn = min(p->next);
        return p->data > mn ? mn : p->data;
    }
}
int max(struct node *p)
{
    int mx;
    if (!p)
        return INT32_MIN;
    else
    {
        mx = max(p->next);
        return p->data > mx ? p->data : mx;
    }
}
node *lenear_search(struct node *p, int key)
{
    struct node *q, *first = p;
    q = p;

    while (p)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return 0;
}
int count_node(struct node *ptr)
{
    if (!ptr)
        return 0;
    return count_node(ptr->next) + 1;
}
void display(struct node *ptr)
{
    // while (ptr!=NULL)
    // {
    //     cout << ptr->data << "-->";
    //    ptr =ptr->next;
    // }

    /* display using recurion easy to reverse*/
    if (!ptr)
        cout << "end;";
    else
    {
        cout << ptr->data << "-->";
        display(ptr->next); // to reverse just call before printing
    }
}

int insert(struct node *p, int index, int key)
{
    struct node *q, *t, *first = p;
    if (index < 0 || index > count_node(first))
        return 0;
    if (index == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        if (first == NULL)
        {
            first = t;
            t->next = NULL;
        }
        else
        {
            t->next = first;
            first = t;
        }
    }
    else if (index > 0)
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        if (p)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = key;
            t->next = p->next;
            p->next = t;
        }
    }
    return 1;
}

void insert_at_last(struct node *p, int key)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = key;
    t->next = NULL;
    while (p != NULL)
    {
        p = p->next;
    }
    if (first == NULL)
        first = t;
    else
        p->next = t;
}

void insert_in_sorted_list(struct node *p, int key)
{
    struct node *q, *t;
    q = p;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = key;

    if (first == NULL)
    {
        t->next = NULL;
        first = t;
    }
    else if (first->data > key)
    {
        t->next = first;
        first = t;
    }
    else
    {
        while (p && p->data < key)
        {
            q = p;
            p = p->next;
        }

        t->next = q->next;
        q->next = t;
    }
}
int deletelist(struct node *p, int index)
{
    struct node *t, *q, *first = p;

    int x = -1;
    if (index == 0)
    {
        x = first->data;
        p = first;
        first = first->next;
        free(p);
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            x = p->data;
            free(p);
        }
    }
    return x;
}
int isSorted(struct node *p)
{
    int x = INT32_MIN;
    while (p)
    {
        if (p->data < x)
            return 0; //if single element is smaller than previous one output unsorted

        x = p->data;
        p = p->next;
    }
    return 1;
}
node *reverse(node *p) // sliding pointer method for reverse ll
{
    node *q, *r;
    r = q = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    q->next = r;
    return q;
}
void Rreverse(node *p, node *q) ///using recursion
{

    if (p)
    {
        Rreverse(p->next, p);

        p->next = q;
    }

    else
    {

        first = q;
    }
}

node *concatinatell(node *p, node *q)
{
    node *first = p;
    while (p->next)
        p = p->next;

    p->next = q;
    free(q);
    return first;
}
node *mergesortedll(node *p, node *q)
{
    node *third, *last;
    if (p->data < q->data)
    {
        third = last = p;
        last->next = NULL;
        p = p->next;
    }
    else
    {
        third = last = q;
        last->next = NULL;
        q = q->next;
    }
    while (q && p)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            last->next = NULL;
            p = p->next;
        }
        else
        {
            last->next = q;
            last = q;
            last->next = NULL;
            q = q->next;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;

    return third;
}

int isLooped(node *p)
{
    node *q = p;
    do
    {

        q = q->next;
        p = p->next;
        p = p ? p->next : NULL;

    } while (p && q && p != q);

    // if(p==q)
    //     return 1;
    //     else
    //         return 0;
    return p == q ? 1 : 0;
}
void distroy(node *p)
{
    node *q = p;
    while (p)
    {
        q = q->next;
        delete p;
        p = q;
    }
    first = NULL;
    cout << "<---memory distroyed--->";
}

int main()
{
    int a[] = {2, 4, 9, 15, 34, 21};
    int s[] = {1, 3, 5, 6, 7};
    first = create(first, a, 6);
    display(first);

    // cout << endl
    //      << count_node(first) << endl;
    // cout << lenear_search(first,2)->data << endl;
    // cout << search(first,2)->data << endl;
    // insert(first, 0, 4);
    // insert(first, 1, 9);
    // insert(first, 4, 6);
    // insert_at_last(first,9);
    // insert_at_last(first,6);
    // insert_at_last(first,3);
    // insert_in_sorted_list(first, 7);
    insert_in_sorted_list(first, 1);
    // insert_in_sorted_list(first, 8);

    // cout
    //     << endl
    //     << min(first) << endl;
    // cout << endl
    //      << max(first) << endl;
    // deletelist(first, 2);
    // deletelist(first, 1);
    cout << "\n";
    // cout << "\n"<< isSorted(first) << endl;
    // first=reverse(first);

    // second = create(second, s, 5);
    // display(second);
    cout << endl;
    // Rreverse(first, NULL);
    display(first);

    // display(concatinatell(first, second));
    // cout << endl;
    // display(mergesortedll(first, second));

    /* to create a loop in list */
    // node *t1, *t2;
    // t1 = first->next->next->next->next;
    // t2 = first->next;
    // t1->next = t2;

    //  cout << isLooped(first);
    //  cout << isLooped(second);
    //  display(first);
    // distroy(first);
    // insert_at_last(first,9);
    // display(first);
    distroy(first);
    return 0;
}
