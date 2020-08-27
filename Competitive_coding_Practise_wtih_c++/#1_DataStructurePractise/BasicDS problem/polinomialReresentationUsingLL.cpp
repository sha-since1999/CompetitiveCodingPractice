#include <bits/stdc++.h>
using namespace std;
struct node
{
    int coefficient;
    int power;
    node *next;
} *first1 = NULL;
void insert(int coeff, int pow)
{
    node *temp = new node[1];
    temp->coefficient = coeff;
    temp->power = pow;
    temp->next = NULL;
    if (first1 == NULL)
    {
        first1 = temp;
        cout << "FF--";
    }
    else
    {
        node *tpt, *ptr = first1;
        while (ptr != NULL)
        {
            cout << "ssss";
            tpt = ptr;
            ptr = ptr->next;
        }
        tpt->next = temp;
    }
}
void eval(int x)
{
    int sum = 0;
    node *temp = first1;
    while (temp)
    {
        sum += temp->coefficient * pow(x, temp->power);
        temp = temp->next;
    }
    cout << "solution :" << sum << endl;
}
int main()
{
    cout << "Enter the degree of polinomial " << endl;
    int degree;
    cin >> degree;
    int coeff, power;

    for (int i = 0; i <= degree; i++)
    {
        cin >> coeff >> power;
        insert(coeff, power);
    }
    cout << "enter the value of \"x\"" << endl;
    int x = 2;
    // cin >> x;
    eval(x);
    cout << "end!" << endl;
    return 0;
}