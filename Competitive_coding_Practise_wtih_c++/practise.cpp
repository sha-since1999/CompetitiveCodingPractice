#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void bubbleSort(int *a, int n)
{
    bool isSorted = false;
    for (int i = 0; i < n; i++)
    {
        isSorted = true;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                isSorted = false;
                swap(a[j], a[j + 1]);
            }
        }
        if (isSorted)
            break;
    }
}
void insertionSort(int *a, int n)
{

    for (int i = 1; i < n; i++)
    {
        int key = a[i], j;
        for (j = i - 1; j >= 0; j--)
        {
            if (key < a[j])
                a[j + 1] = a[j];
            else
                break;
        }
        a[j + 1] = key;
    }
}

void selectionSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int key = a[i], j;
        for (j = i; j < n; j++)
        {
            if (a[j] < key)
                key = j;
        }
        swap(a[key], a[i]);
    }
}

void deleteHeap(int *a, int n)
{
    swap(a[1], a[n]);
    int i = 1;
    int j = 2 * i;
    while (j < n - 1)
    {
        if (a[j] < a[j + 1])
            j++;
        if (a[j] > a[i])
            swap(a[j], a[i]);

        i = j;
        j = 2 * i;
    }
}
void insertHeap(int *a, int j)
{
    int key = a[j];
    while (j > 1)
    {
        if (a[j / 2] < key)
        {
            a[j] = a[j / 2];
            j /= 2;
        }
        else
            break;
    }
    a[j] = key;
}

void createHeap(int *a, int n)
{
    for (int i = 2; i <= n; i++)
        insertHeap(a, i);
}

void heapSort(int *a, int n)
{
    createHeap(a, n);
    for (int i = 0; i < n - 1; i++)
    {
        deleteHeap(a, n - i);
    }
}
int main()
{

    int a[] = {0, 5, 1, 6, 9, 7, 3, 2};
    int n = 8;
    // insertionSort(a, n);

    // for (int i = 0; i < n; i++)
    //     cout << a[i] << " ";
    // selectionSort(a, n);

    bubbleSort(a, n);
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    // heap sort takes an array index from 1 to n for better iteration
    // heapSort(a, 7);
    // for (int i = 1; i < n; i++)
    //     cout << a[i] << " ";

    return 0;
}

