#include <iostream>
using namespace std;
class node
{
public:
    node *next;
    int data;
};
class stackLL
{
private:
    node *first;

public:
    stackLL()
    {
        first = NULL;
    }
    ~stackLL()
    {
        node *temp;
        while (first = NULL)
        {
            temp = first->next;
            delete[] first;
            first = temp;
        }
    }

    int push(int);
    int pop(void);
    int isFull(void);
    int isEmpty(void);
    int peek(int);
    int stackTop(void);
};
int stackLL::push(int key)
{
    if (isFull())
    {
        cout << "stack Overflow" << endl;
        return -1;
    }
    node *temp = new node[1];
    temp->data = key;
    temp->next = NULL;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        temp->next = first;
        first = temp;
    }
    return 1;
}

int stackLL::pop()
{
    if (isEmpty())
    {
        cout << "stack Underflow" << endl;
        return 0;
    }

    int data = first->data;
    node *temp = first;
    first = first->next;
    delete[] temp; //after popup an element free last block of memory
    return data;
}
int stackLL::peek(int key)
{
    int pos = 1;
    node *temp = first;
    while (temp)
    {
        if (temp->data == key)
        {
            return pos;
        }
        pos++;
        temp = temp->next;
    }
    cout << "invalid key" << endl;
    return -1;
}
int stackLL::isFull(void)
{
    node *temp = new node[1];
    if (temp == NULL)
        return 1;
    delete[] temp;
    return 0;
}
int stackLL::isEmpty(void)
{
    if (first == NULL)
        return 1;
    return 0;
}
int stackLL ::stackTop(void)
{
    if (first == NULL)
        return 0;
    return first->data;
}
int main(int argc, const char **argv)
{
    stackLL stk1;
    stk1.push(1);
    stk1.push(2);
    stk1.push(3);
    stk1.push(4);
    // cout << stk1.isEmpty() << endl;
    cout <<"positon of 2:" <<stk1.peek(2) << endl;
    while(!stk1.isEmpty())
    {
        cout << stk1.pop() << endl;

    }
   
    stk1.pop();

    // cout << stk1.isEmpty() << endl;
    cout << stk1.peek(2) << endl;


    return 0;
}
