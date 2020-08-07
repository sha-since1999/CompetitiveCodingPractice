#include <bits/stdc++.h>
using namespace std;

class stak
{
public:
    int *A = new int[5];
    int top;
    int size;
    // stak(int size)
    // {
    //     A = new int[size];
    //     top = -1;
    //     this->size = size;
    // }
    void push(int data);
    int pop();
    int stackTop();
};
void stak::push(int data)
{
    if (top == size - 1)
        cout << "stak OverFlow" << endl;
    else
    {
        top++;
        A[top] = data;
    }
}
int stak::pop()
{
    if (top == -1)
        return -1;
    else
    {
        top--;
    }
    return 1;
}
int stak::stackTop()
{
    if (top == -1)
        return -1;
    return A[top];
}

class queueUsingstak
{
private:
    int data;
    int sz;
    stak stkeq, stkdq;

public:
    queueUsingstak(int size = 10)
    {
        this->sz = size;
    }
    // ~queueUsingstak()
    // {
    //     delete []stkeq.A;
    //     delete []stkdq.A;
    // }
    void enqueue(int);
    void dequeue(void);
    void front(void);
    void back(void);
};

void queueUsingstak::enqueue(int data)
{
    if (stkeq.top == stkeq.size - 1)
    {
        if (stkdq.top == -1)
            while (stkeq.top == -1)
            {
                stkdq.push(stkeq.stackTop());
                stkeq.pop();
            }
    }
    else if (stkeq.stackTop() == stkeq.size - 1 && stkdq.stackTop() != -1)
    {
        cout << "queue is full" << endl;
    }
    else
    {
        stkeq.push(data);
    }
}
void queueUsingstak::dequeue()
{
    if (stkdq.top == -1)
    {
        while (stkeq.top != -1)
        {
            stkdq.push(stkeq.stackTop());
            stkeq.pop();
        }
        if (stkeq.top == -1)
            cout << "Empty Queue" << endl;
    }
    else
    {
        stkdq.pop();
    }
}
void queueUsingstak::front()
{
    if (stkdq.top == -1)
    {
        if (stkeq.top == -1)
            cout << "Empty Queue" << endl;
        else
        {
            while (stkeq.top != -1)
            {
                stkdq.push(stkeq.stackTop());
                stkeq.pop();
            }
            cout << stkdq.stackTop() << endl;
        }
    }
    else
        cout << stkdq.stackTop() << endl;
}
void queueUsingstak::back()
{
    if (stkeq.top == -1)
    {
        if (stkdq.top == -1)
        {
            cout << "Empty queue" << endl;
        }
        else
        {
            while (stkeq.top != -1)
            {
                stkeq.push(stkdq.stackTop());
                stkdq.pop();
            }
            cout << stkeq.stackTop() << endl;
        }
    }
    else
        cout << stkeq.stackTop() << endl;
}

int main()
{
    // stak stk1(5);
    // stk1.push(1);
    // stk1.push(4);
    // stk1.push(8);
    // stk1.pop();
    // stk1.pop();
    // cout << stk1.stackTop() << endl;
    queueUsingstak qu(20);
    qu.enqueue(4);
    qu.enqueue(5);
    qu.enqueue(6);
    qu.enqueue(7);

    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.back();
    qu.front();

    return 0;
}

//incompele
//incompele
//incompele
//incompele
//incompele
//incompele