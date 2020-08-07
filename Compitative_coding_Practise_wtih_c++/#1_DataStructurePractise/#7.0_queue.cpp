#include <iostream>
using namespace std;
class Queue
{
private:
    int *Q;
    int size;
    int rear;
    int front;

public:
    Queue(int size)
    {
        this->size = size;
        this->Q = new int[size];
        rear = -1;
        front = -1;
    }
    ~Queue()
    {
        delete[] Q;
    }
    void display(void);
    int enqueue(int);
    int dequeue();
    int isEmpty();
    int isFull();
    int last(void);
    int first(void);
    int peek(int);
};
void Queue::display(void)
{
    if (isEmpty())
    {
        cout << "queue is Empty" << endl;
        return;
    }
    int i = front + 1;
    while (i != rear + 1)
    {
        cout << Q[i] << endl;
        i++;
    }
    return;
}
int Queue::enqueue(int key)
{
    if (isFull())
    {
        cout << "queue Overgflow" << endl;
        return -1;
    }
    rear++;
    Q[rear] = key;
    return 1;
}
int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "queue Underflow" << endl;
        return -1;
    }
    front++;
    int data = Q[front];
    return data;
}
int Queue::isEmpty()
{
    if (front == rear)
        return 1;
    return 0;
}
int Queue::isFull()
{
    if (rear == size - 1)
        return 1;
    return 0;
}
int Queue::last()
{
    if (isEmpty())
    {
        cout << "queue Underflow" << endl;
        return -1;
    }
    return Q[rear];
}
int Queue::first()
{
    if (isEmpty())
    {
        cout << "queue Underflow" << endl;
        return -1;
    }
    return Q[front + 1];
}
int Queue::peek(int key)
{
    int i = front + 1;
    int pos = 1;
    while (i != rear + 1)
    {
        if (Q[i] == key)
            return pos;
        i++;
    }
    cout << "invalid key" << endl;
    return -1;
}
int main()
{
    Queue q1(4);
    q1.enqueue(3);
    cout << q1.isEmpty() << endl;

    q1.enqueue(2);
    q1.enqueue(6);
    q1.enqueue(5);
    q1.enqueue(8);
    // q1.display();
    cout << q1.last() << endl;
    cout << q1.first() << endl;

    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    // q1.dequeue();
    // q1.display();
    q1.peek(5);
    cout << q1.isEmpty() << endl;
    cout << q1.isFull() << endl;

    return 0;
}