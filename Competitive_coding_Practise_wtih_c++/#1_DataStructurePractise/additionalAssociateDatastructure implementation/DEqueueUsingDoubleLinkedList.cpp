#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
};

class dequeue
{
private:
    node *front;
    node *rear;
    int size;

public:
    dequeue()
    {
        front = rear = NULL;
        size = 0;
    }
    ~dequeue()
    {
        while (front)
        {
            rear = front;
            front = front->next;
            delete[] rear;
        }
    }
    void display();
    void erase();
    void insertfront(int data);
    void insertback(int data);
    void deletefront(void);
    void deleteback(void);
    int isEmpty();
    int getfront();
    int getback();
};
void dequeue::display(void)
{
    if (isEmpty())
        cout << "no item to dislay" << endl;
    else
    {
        node *temp = front;
        while (temp)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
    }
}
void dequeue::insertfront(int data)
{

    node *temp = new node;
    if (temp == NULL)
        cout << "Over flow" << endl;
    else
    {
        temp->data = data;
        temp->next = temp->prev = NULL;
        if (front == NULL)
            front = rear = temp;
        else
        {
            front->prev = temp;
            temp->next = front;
            front = temp;
        }
        size++;
    }
}
void dequeue::insertback(int data)
{
    node *temp = new node;
    if (temp == NULL)
        cout << "Over flow" << endl;

    else
    {
        temp->data = data;
        temp->next = temp->prev = NULL;
        if (front == NULL)
            front = rear = temp;
        else
        {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
        size++;
    }
}
void dequeue::deletefront(void)
{
    if (isEmpty())
    {
        cout << "Under flow" << endl;
    }

    else
    {
        node *temp = front;
        front = front->next;
        front->prev = NULL;
        delete[] temp;
        size--;
    }
}
void dequeue::deleteback(void)
{
    if (isEmpty())
    {
        cout << "Under flow" << endl;
    }
    else
    {
        node *temp = rear;
        rear = rear->prev;
        rear->next = NULL;
        delete[] temp;
        size--;
    }
}
int dequeue::isEmpty()
{
    if (front == NULL)
        return 1;

    return 0;
}
int dequeue::getback()
{
    if (isEmpty())
        return -1;

    return rear->data;
}
int dequeue::getfront()
{
    if (isEmpty())
        return -1;
    return front->data;
}
void dequeue::erase()
{
    while (front)
    {
        rear = front;
        front = front->next;
        delete[] rear;
    }
}

int main()
{
    dequeue dq;
    dq.insertfront(4);
    dq.insertfront(43);
    dq.insertfront(41);
    dq.insertback(32);
    dq.insertback(6);
    dq.insertback(5);
    dq.display();
    cout << endl
         << dq.getback() << endl;
    cout << dq.getfront() << endl;
    cout << dq.isEmpty() << endl;
    dq.erase();
    cout << dq.isEmpty() << endl;
    dq.display();

    return 0;
}