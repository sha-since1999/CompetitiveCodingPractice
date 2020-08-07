#include <iostream>
using namespace std;

class node
{
public:
    node *next;
    int data;
};

class circularLL
{
private:
    node *head;

public:
    circularLL()
    {
        head = NULL;
    }
    ~circularLL()
    {
        node *q, *last;
        q = last = head;
        do
        {
            q = q->next;
            delete[] head;
            head = q;
        } while (head != last);
        cout << "\n<---distroyed-->" << endl;
    }
    void display();
    void create(int *, int);
    int insert(int index, int key);
    int delete_node(int key);
    int length();
};

void circularLL::display()
{
    node *p = head;
    do
    {
        cout << p->data << "-->";
        p = p->next;

    } while (p != head);

    if (p == head)
        cout << "end" << endl;
}

void circularLL::create(int *a, int n)
{
    node *t, *p, *last;
    t = new node;
    t->data = a[0];
    t->next = NULL;
    head = last = t;

    for (int i = 1; i < n; i++)
    {
        p = new node;
        p->data = a[i];
        last->next = p;
        last = p;
        last->next = head;
    }
}
int circularLL::length()
{
    node *p = head;
    int length = 0;
    do
    {
        p = p->next;
        length++;

    } while (p != head);
    return length;
}
int circularLL::insert(int index, int key)
{
    node *p = head, *q, *t;
    t = new node;
    t->data = key;
    t->next = NULL;

    if (index < 0 || index > length())
        return 0;
    if (head == NULL)
    {
        head = t;
        t->next = head;
    }

    if (index > 0)
    {

        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
    else
    {
        do
        {
            q = p;
            p = p->next;

        } while (p->next != head);
        t->next = head;
        p->next = t;
        head = t;
    }
    return 1;
}

int circulaLL::delete_node(int)
{

} 
int main()
{
    int a[] = {1, 2, 23, 4, 5, 656, 54, 8, 3};
    circularLL cll;
    cll.create(a, 9);
    cll.display();
    // cout << cll.length() << endl;
    cll.insert(1, 101);
    cll.display();

    return 0;
}