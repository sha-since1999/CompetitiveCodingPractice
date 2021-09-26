#include <bits/stdc++.h>
using namespace std;

class fun
{
public:
    void operator()()
    {
        cout << "hello sahu" << endl;
    }
    void operator()(string s)
    {
        cout << "hello " << s << endl;
    }
};
int main()
{
    fun f; // constructor
    f();   // overloaded operator () = function call where f is an object
    f("rohit");

    return 0;
}