#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class diagonal_matrix

{
private:
    int *A;
    int length;
    int size;

public:
    diagonal_matrix(int size)
    {
        this->size = size;
        A = new int[size];
        length = 0;
    }
    ~diagonal_matrix()
    {
        delete[] A;
    }
    void display();
    int set(int);
    int get(int);
};
class matrix
{

private:
    int *A;
    int length;
    int row;
    int column;

public:
    matrix(int r, int c)
    {
        row = r;
        column = c;
        length = 0;
        A = new int[30];
    }
    ~matrix()
    {
        delete[] A;
    }
    int set(int, int, int);
    int get(int);
    void display();
};
void matrix ::display()
{
    cout << "<<--- daigoanal matrix here---->" << endl;

    for (int i = 01; i <= row; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            if (j > i)
                cout << "0 ";

            else
            {
                cout << A[i * (i - 1) / 2 + j - 1] << " ";
            }
        }
        cout << endl;
    }
}
int matrix ::set(int key, int i, int j)
{
    if (i >= j)
    {
        A[(i * (i - 1) / 2) + j - 1] = key;
        length++;
    }

    return 0;
}

int matrix::get(int key)
{
    int index;
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
            index = i;
    }
    // A[n *(n - 1) / 2+j-1];
    int sum = 0;
    int x;
    for (int i = 0; i < length; i++)
    {
        if ((index - sum) < 0)
        {
            x = i - 1;
            sum = sum - i;
            break;
        }
        sum = sum + i;
    }
    cout << "(" << x << "," << index - sum << ")";
    return 1;
}

void diagonal_matrix ::display()
{
    cout << "<<--- daigoanal matrix here---->" << endl;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (i == j)
                cout << A[i] << " ";
            else
            {
                cout << "0"
                     << " ";
            }
        }
        cout << endl;
    }
}

int diagonal_matrix::set(int key)
{
    A[length] = key;
    length++;
    return 1;
}

// int diagonal_matrix::get(int key)
// {

// }

int main()
{
    int key;
    // int n;
    // cout << "enter the size of diagonal matrix:" << endl;
    // cin >> n;
    // diagonal_matrix dia1(n);
    // cout << "enter diagonal element:" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> key;
    //     dia1.set(key);
    // }
    // dia1.display();

    int row;
    int column;
    cout << "enter the size of row and column matrix:" << endl;
    cin >> row >> column;
    matrix ltm(row, column);
    cout << "enter element of tringular matrix:" << endl;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            cin >> key;
            ltm.set(key, i, j);
        }
    }
    ltm.display();

    cout << "enter key to get their index " << endl;
    cin >> key;
    ltm.get(key);
    return 0;
}