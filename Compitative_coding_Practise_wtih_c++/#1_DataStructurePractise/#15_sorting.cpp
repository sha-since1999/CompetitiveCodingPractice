#include <bits/stdc++.h>
using namespace std;

class Sort
{
private:
    int i, j, key;
    static const int size = 10;

public:
    int A[10] = {7, 4, 3, 5, 12, 8, 9, 6, 47, 1};
    Sort()
    {
        i = j = key = 0;
    }
    void displaySortedArray();
    void insertionSort();
    void selectionSort();
    void bubbleSort();
    void countSort();
    void mergeSort(int, int);
    void merge(int, int, int);
    void quickSort(int l = 0, int h = size);
    int partition(int, int);
    void swap(int *, int *);
    void shellSort(void);
    void radixSort(void);
};
void Sort::swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Sort::displaySortedArray()
{
    for (i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}
void Sort::insertionSort()
{
    for (i = 1; i < size; i++)
    {
        j = i - 1;
        key = A[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (key < A[j])
                A[j + 1] = A[j];
            else
                break;
        }
        A[j + 1] = key;
    }
}
void Sort::selectionSort()
{
    for (i = 0; i < size - 1; i++)
    {
        key = i;
        for (j = i; j < size; j++)
        {
            if (A[j] < A[key])
                key = j;
        }
        swap(&A[i], &A[key]);
    }
}
void Sort::bubbleSort()
{
    int flag = 0;
    for (i = 1; i < size; i++)
    {
        for (j = 0; j < size - i; j++)
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        if (flag == 0)
            break; //to make it adaptive
    }
}
void Sort::quickSort(int l, int h)
{
    if (l < h)
    {
        int p = partition(l, h);
        quickSort(l, p);
        quickSort(p + 1, h);
    }
}
int Sort::partition(int l, int h)
{
    key = A[l];
    int i = l;
    while (l < h)
    {
        do
        {
            l++;
        } while (A[l] <= key);

        do
        {
            h--;
        } while (A[h] > key);

        if (l < h)
            swap(&A[l], &A[h]);
    }
    swap(&A[i], &A[h]);

    return h;
}
void Sort::mergeSort(int l, int h)
{
    if (l < h)
    {
        int mid = floor((l + h) / 2);
        mergeSort(l, mid);
        mergeSort(mid + 1, h);
        merge(l, mid, h);
    }
}
void Sort::merge(int n, int mid, int m)
{
    int M[m + 1];
    int k = i = n;
    j = mid + 1;

    while (i <= mid && j <= m)
    {
        if (A[i] > A[j])
            M[k++] = A[j++];
        else
            M[k++] = A[i++];
    }
    for (; i <= mid; i++)
        M[k++] = A[i];
    for (; j <= m; j++)
        M[k++] = A[j];

    for (i = n; i <= m; i++)
        A[i] = M[i];
}
void Sort::countSort()
{
    int max = INT_MIN;
    for (i = 0; i < size; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    int c[max + 1] = {0};
    for (j = 0; j < size; j++)
        c[A[j]]++;
    j = 0;
    for (i = 0; i <= max; i++)
        if (c[i] > 0)
        {
            A[j++] = i;
            c[i]--;
        }
}
int main()
{
    Sort S;
    // S.insertionSort();
    // S.selectionSort();
    // S.bubbleSort();
    // S.quickSort();
    // S.mergeSort(0, 9);
    // S.countSort();
    S.displaySortedArray();
    return 0;
}

// every thing in it  well tested only
// two things remain two implement radix sort and shell sort