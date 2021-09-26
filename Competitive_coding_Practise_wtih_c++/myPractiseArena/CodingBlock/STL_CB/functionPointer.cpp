#include <bits/stdc++.h>
using namespace std;

int sum(int a, int b)
{
    return a + b;
}
int main()
{
    int (*sm)(int, int); // function pointer declaration
    sm = &sum; // function pointer initialisation
    int a = (*sm)(4, 5); // function call using function pointer  or dereference function pointer
    cout << a << endl;
    return 0;
}