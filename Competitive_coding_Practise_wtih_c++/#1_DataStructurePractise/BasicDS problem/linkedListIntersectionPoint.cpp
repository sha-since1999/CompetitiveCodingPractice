#include <iostream>
using namespace std;
class node
{
public:
    node *next;
    int data;
};
class linkedList
{
public:
    node *first = NULL;

    void create(int a[], int n)
    {
        node *p, *t, *last;
        t = new node;
        t->data = a[0];
        t->next = NULL;
        first = last = t;
        for (int i = 1; i < n; i++)
        {
            t = new node;
            t->data = a[i];
            last->next = t;
            last = t;
            last->next = NULL;
        }
    }
    void display()
    {
        node *p = first;
        while (p)
        {
            cout << p->data << "-->";
            p = p->next;
        }
        cout << "end\n"
             << endl;
    }
};

template <class T>
class array
{
public:
    T *A;
    int length;
    int size;
    array(int size)
    {
        A = new T[size];
        this->size = size;
        length = 0;
    }
    int push(T key)
    {
        A[length] = key;
        length++;
        return 1;
    }
    T pop()
    {
        length--;
        return A[length];
    }
    T top()
    {
        return A[length - 1];
    }
};

int main()
{
    array<node *> stk1(20), stk2(10);
    // stk1.push(1);
    // stk1.push(12);
    // stk1.push(13);
    // cout << stk1.length << endl;
    // stk2.push(2);
    // stk2.push(21);
    // stk2.push(23);
    cout << stk2.length << endl;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int s[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    linkedList ll1, ll2;
    ll1.create(a, 9);
    ll1.display();
    ll2.create(s, 9);
    ll2.display();
    node *t1, *t2;
    t1 = ll1.first->next->next->next;
    t2 = ll2.first->next->next->next;
    t2->next = t1;
    node *p = ll1.first, *q = ll2.first;

    while (p)
    {
        stk1.push(p);
        p = p->next;
    }

    while (q)
    {
        stk2.push(q);
        q = q->next;
    }
    node *data;
    while (stk1.top() == stk2.top())
    {
        data = stk1.pop();
        stk2.pop();
    }
     cout << stk1.length << endl;
     cout << stk2.length << endl;
    ll1.display();
    ll2.display();
    cout << "intersection point:" << data->data << endl;

    return 0;
}