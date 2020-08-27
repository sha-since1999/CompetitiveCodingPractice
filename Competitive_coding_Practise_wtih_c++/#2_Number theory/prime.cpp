#include <iostream>
using namespace std;
string prime(int j)
{
    int flag = 0;
    for (int i = 2; i < (j / 2) + 1; i++)
    {
        if (j % i == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1 || j == 1)
    {
        return "not prime";
    }
    return "prime";
}

int main()
{ while (1){
    int i;
    char ch;

    cout << "enter any key to continue" << endl;

    cin >> ch;
    cout << "enter the no to find wheather nois prime or not " << endl;
    cin >> i;
    cout << "given no is " << prime(i) << endl<<endl;
    if (ch=='x')
    {
        exit;
    }
}
    return 0;
}