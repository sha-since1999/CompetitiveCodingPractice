#include <iostream>
using namespace std;
class Stack
{
private:
    int size;
    int top;
    int *S;

public:
    Stack(int size);
    ~Stack();
    int push(int);
    int pop(void);
    int peek(int);
    int isEmpty();
    int isFull();
    int stackTop(void);
};

Stack::Stack(int size)
{
    this->size = size;
    top = -1;
    this->S = new int[size];
}

Stack::~Stack()
{
    delete[] S;
}

int Stack::push(int key)
{
    if (isFull())
    {
        cout << "stack Overflow" << endl;
        return 0;
    }
    top++;
    S[top] = key;
    return 1;
}
int Stack::pop(void)
{
    if (isEmpty())
    {
        cout << "stack Underflow" << endl;
        return 0;
    }
    top--;
    return S[top + 1];
}
int Stack::peek(int key)
{
    if (isEmpty())
        cout << "invalid Operation" << endl;
    int pos = top+1;
    while (pos--)
    {
        if (S[pos] == key)
            return top - pos+1;
    }
    return 0;
}
int Stack::isEmpty(void)
{
    if (top == -1)
        return 1;
    return 0;
}
int Stack::isFull(void)
{
    if (top == size - 1)
        return 1;
    return 0;
}
int Stack::stackTop(void)
{
    return S[top];
}

int main(int argc, const char **argv)
{
    Stack stk1(4);
    stk1.push(2);
    stk1.push(3);
    stk1.push(4);
    stk1.push(1);
    cout << stk1.peek(2) << endl;

    while (!stk1.isEmpty())
    {
        cout << stk1.pop() << endl;
    }
    cout << stk1.isEmpty() << endl;
    cout << stk1.isFull() << endl;

    return 0;
}