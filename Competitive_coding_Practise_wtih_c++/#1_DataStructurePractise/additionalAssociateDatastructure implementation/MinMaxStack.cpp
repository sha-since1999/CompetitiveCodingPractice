#include <bits/stdc++.h>
using namespace std;
template <class T>
class MinMaxStack
{
    stack<T> st, mnst, mxst;

public:
    void push(T x)
    {

        st.push(x);
        if (mnst.empty() or mxst.empty())
            mnst.push(x), mxst.push(x);
        else if (x < mnst.top())
            mnst.push(x), mxst.push(mxst.top());
        else if (x > mxst.top())
            mxst.push(x), mnst.push(mnst.top());
        else
            mnst.push(mnst.top()), mxst.push(mxst.top());
    }

    void pop()
    {
        st.pop();
        mnst.pop();
        mxst.pop();
    }

    T top()
    {
        return st.top();
    }

    T getMin()
    {
        return mnst.top();
    }
    T getMax()
    {
        return mxst.top();
    }
};

int main()
{
    MinMaxStack<int> mnxst;

    mnxst.push(5);
    mnxst.push(-2);
    mnxst.push(20);
    mnxst.push(0);
    mnxst.push(2);
    mnxst.push(-10);
    cout << mnxst.top() << endl;
    mnxst.pop();
    cout << mnxst.getMin() << endl;
    cout << mnxst.getMax() << endl;
    mnxst.pop();

    return 0;
}

// note : motivation of the program to get min and max value of the stack in constant time O(1)