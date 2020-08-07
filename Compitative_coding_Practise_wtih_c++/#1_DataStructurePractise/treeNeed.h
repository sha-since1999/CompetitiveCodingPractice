
#ifndef TREE_ESSENTIALS
#define TREE_ESSENTIALS
class node
{

public:
    node *lchild;
    int data;
    node *rchild;
    node()
    {
    }
};
node *infy = new node;
node *infy_node_pointer()
{
    infy->lchild = infy->rchild = NULL;
    infy->data = INT32_MAX;
    return infy;
}
node *minus_infy_node_pointer()
{
    infy->lchild = infy->rchild = NULL;
    infy->data = INT32_MIN;
    return infy;
}

class queue
{
private:
    node **Q;
    int size;
    int front;
    int rear;

public:
    queue(int size)
    {
        this->size = size;
        Q = new node *[size];
        rear = front = 0;
    }
    ~queue()
    {
        delete[] Q;
    }
    int enqueue(node *);
    node *dequeue(void);
    int isEmpty(void);
};
int queue::enqueue(node *key)
{
    if ((rear + 1) % size == front)
        return -1;
    rear = (rear + 1) % size;
    Q[rear] = key;
    return 0;
}
node *queue::dequeue(void)
{
    if (isEmpty())
        return NULL;
    front = (front + 1) % size;
    return Q[front];
}
int queue::isEmpty(void)
{
    if (rear == front)
        return 1;
    return 0;
}

class stack
{
private:
    int top;
    node **S;
    int size;

public:
    stack(int size)
    {
        this->size = size;
        top = -1;
        S = new node *[size];
    }
    ~stack()
    {
        delete[] S;
    }
    int push(node *);
    node *pop(void);
    node *stackTop(void);
    int isEmpty(void);
};
int stack ::push(node *key)
{
    if (top == size - 1)
        return -1;
    top++;
    S[top] = key;
    return 0;
}
node *stack::pop(void)
{
    if (top == -1)
        return NULL;

    return S[top--];
}
int stack::isEmpty(void)
{
    if (top == -1)
        return 1;
    return 0;
}
node *stack::stackTop(void)
{
    if (isEmpty())
    {

        return NULL;
    }
    return S[top];
}

#endif //treeNeed
