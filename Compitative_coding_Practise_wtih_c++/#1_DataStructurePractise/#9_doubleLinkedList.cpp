#include <iostream>
using namespace std;
class node
{
public:
    node *next;
    node *prev;
    int data;
};
class doublyLinkedList
{
private:
    node *first;

public:
    doublyLinkedList()
    {
        first = NULL;
    }
    ~doublyLinkedList()
    {
        node *p;
        while (first)
        {
            p = first;
            first = first->next;
            delete p;
        }
        cout << "\n<--destroyed-->" << endl;
    }
    void display();
    void create(int *, int n);
    int insert(int index, int key);
    int delete_node(int key);
    void reverse();
    int length()
    {
        int l = 0;
        node *p = first;
        while (p)
        {
            l++;
            p = p->next;
        }
        return l;
    }
};

void doublyLinkedList::create(int a[], int n)
{
    node *p, *last, *t;
    t = new node;
    t->data = a[0];
    t->next = t->prev = NULL;
    first = last = t;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->prev = last;
        last->next = t;
        last = t;
        last->next = NULL;
    }
}
void doublyLinkedList::display()
{
    node *p = first;
    while (p)
    {
        cout << p->data << "-->";
        p = p->next;
    }
    if (!p)
        cout << "end\n"
             << endl;
}

int doublyLinkedList::insert(int index, int key)
{
    node *p = first, *q, *t;
    if (index < 0 || index > length())
        return 0;

    t = new node;
    t->data = key;
    t->next = t->prev = NULL;
    if (first == NULL)
    {
        first = t;
        cout << "insert:" << key << endl;
        return 1;
    }
    else if (index == 0)
    {
        first->prev = t;
        t->next = first;
        first = t;
        cout << "insert:" << key << endl;
        return 1;
    }
    for (int i = 0; i < index - 1; i++)
        p = p->next;
    t->next = p->next;
    t->next->prev = t;
    t->prev = p;
    p->next = t;
    cout << "insert:" << key << endl;
    return 1;
}
int doublyLinkedList::delete_node(int key)
{
    node *p = first;
    int x;
    if (first == NULL)
        return 0;
    while (p)
    {
        if (p->data == key)
        {
            x = p->data;
            break;
        }
        p = p->next;
    }
    if (p == first)
    {
        first = first->next;
        delete p;
    }
    else
    {
        p->next->prev = p->prev;
        p->prev->next = p->next;
        delete p;
    }
    cout << "delete:" << key << endl;
    return x;
}
void doublyLinkedList::reverse()
{
    node *p = first, *temp;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p && p->next == NULL)
            first = p;
    }
    cout << "reverse:-)" << endl;
}
int main()
{
    int a[] = {1, 2, 3, 5, 23, 77, 40, 23};
    doublyLinkedList dll;
    dll.create(a, 8);
    dll.insert(0, 22);
    dll.insert(4, 21);
    dll.display();
    dll.delete_node(21);
    dll.reverse();
    dll.display();
    cout << "length:" << dll.length() << endl;

    return 0;
}
