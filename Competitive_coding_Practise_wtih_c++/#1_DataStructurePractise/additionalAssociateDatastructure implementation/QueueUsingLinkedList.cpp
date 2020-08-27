#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *Next;
};
class QueueCLL
{
private:
    node *Rear;
    node *Front;

public:
    QueueCLL();
    ~QueueCLL();
    void display(void);
    int enqueue(int data);
    int dequeue(void);
    int isFull(void);
    int isEmpty(void);
    int peek(int key);
    int first(void);
    int last(void);
};

QueueCLL::QueueCLL()
{
    Front = Rear = 0;
}

QueueCLL::~QueueCLL()
{
    node *temp = Front;
    while (temp)
    {
        Front = temp->Next;
        delete[] temp;
        temp = temp->Next;
    }
}

int QueueCLL::enqueue(int data)
{
    if (isFull())
    {
        cout << "Queue is Overflow" << endl;
        return -1;
    }
    node *temp = new node[1];
    temp->data = data;
    temp->Next = NULL;
    if (isEmpty())
    {
        Front = Rear = temp;
    }
    else
    {
        Rear->Next = temp;
        Rear = temp;
        return 1;
    }

    return 0;
}
int QueueCLL::dequeue(void)
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    else
    {
        node *temp = Front;
        Front = Front->Next;
        delete[] temp;
        return 1;
    }
    return 0;
}
void QueueCLL::display(void)
{
    node *temp = Front;
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->Next;
    }
    return;
}
int QueueCLL::isFull(void)
{
    node *temp = new node[1];
    if (temp == NULL)
        return 1;
    delete[] temp;
    return 0;
}
int QueueCLL::isEmpty(void)
{
    if (Front == NULL)
        return 1;
    return 0;
}
int QueueCLL::peek(int key)
{
    node *temp = Front;
    int pos = 1;
    while (temp)
    {
        if (temp->data == key)
            return pos;
        pos++;
        temp = temp->Next;
    }
    cout << "invalid key" << endl;
    return 0;
}
int QueueCLL::first(void)
{
    if (isEmpty())
    {
        cout << "queue is Empty" << endl;
        return -1;
    }
    return Front->data;
}
int QueueCLL::last(void)
{
    if (isEmpty())
    {
        cout << "queue is Empty" << endl;
        return -1;
    }
    return Rear->data;
}

int main()
{
    QueueCLL q1;
    cout << q1.isEmpty() << endl;
    q1.enqueue(3);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.display();
    // q1.dequeue();
    // q1.dequeue();
    q1.display();
    cout << q1.peek(6) << endl;
    cout << q1.peek(8) << endl;
    cout << q1.isEmpty() << endl;
    cout << q1.isFull() << endl;
    cout << q1.last() << endl;
    cout << q1.first() << endl;
    /* Everything has been cheked*/
    return 0;
}