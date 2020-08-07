#include <iostream>
using namespace std;
class Queue
{
private:
    int *Q;
    int size;
    int front;
    int rear;

public:
    Queue(int size)
    {
        this->size = size;
        Q = new int[size];
        front = rear = 0;
    }
    ~Queue()
    {
        delete[] Q;
    }
    void display(void);
    int dequeue(void);
    int enqueue(int);
    int peek(int);
    int isFull();
    int isEmpty();
    int last();
    int first();
};
void Queue::display()
{
    if (isEmpty())
    {
        cout << "queue is empty" << endl;
        return;
    }
    else
    {
        int i = front + 1;
        do
        {
            cout << Q[i] << endl;
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        return;
    }
}
int Queue::enqueue(int data)
{
    if (isFull())
    {
        cout << "Queue is Full" << endl;
        return -1;
    }
    rear = (rear + 1) % size;
    Q[rear] = data;
    return 1;
}
int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    front = (front + 1) % size;
    return Q[front];
}
int Queue::isEmpty()
{
    if (front == rear)
        return 1;
    return 0;
}
int Queue::isFull()
{
    if ((rear + 1) % size == front)
        return 1;
    return 0;
}
int Queue::last()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    else
        return Q[rear];
}
int Queue::first()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    return Q[(front + 1) % size];
}
int Queue::peek(int key)
{
    int pos = 1;
    int i = front + 1;
    do
    {
        if (Q[i] == key)
            return pos;
        i = (i + 1) % size;
        pos++;
    } while (i != (rear + 1) % size);
    cout << "invalid key" << endl;
    return -1;
}

int main()
{
    Queue q1(4);
    cout << q1.isEmpty() << endl;
    q1.enqueue(6);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);

    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    q1.display();
    cout << q1.peek(8) << endl;

    cout << "first Element: " << q1.first() << endl;
    cout << "last Element: " << q1.last() << endl;
    cout << q1.isEmpty() << endl;
    cout << q1.isFull() << endl;

    return 0;
}