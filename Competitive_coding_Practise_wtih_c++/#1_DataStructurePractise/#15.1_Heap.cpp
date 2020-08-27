#include <bits/stdc++.h>
using namespace std;
class heap
{
private:
    int size;

public:
    heap(int n)
    {
        this->size = n;
    }
    ~heap()
    {
    }
    void insert(int *, int key);
    void create(int *);
    void display(int *);
    void swap(int *, int *);
    void create(int *, int);
    void delete_heap(int *, int);
    void sort(int *);
};
void heap::swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// void heap::insert(int *H, int n) //this is simple method by sir
// {
//     int i = n;
//     int temp = H[i];
//     while (i > 1 && H[i / 2] < temp)
//     {
//         H[i] = H[i / 2];
//         i = i / 2;
//     }
//     H[i] = temp;
// }
void heap::insert(int *H, int i) //this is little bit reliable by me
{
    while (i > 1)
        if (H[i] > H[i / 2])
        {
            swap(&H[i], &H[i / 2]);
            i = i / 2;
        }
        else
            break;
}
void heap::create(int *A)
{
    for (int i = 2; i < size; i++)
        insert(A, i);
}
void heap::display(int *H)
{
    for (int i = 1; i < size; i++)
        cout << H[i] << " ";

    /*this is test write code for display elment of heap treating as tree*/

    // queue<int> qu;
    // int i = 1;
    // qu.push(i);
    // cout << H[i] << " ";
    // while (!qu.empty())
    // {
    //     i = qu.front();
    //     qu.pop();
    //     if (2 * i < n)
    //     {
    //         cout << H[2 * i] << " ";
    //         qu.push(2 * i);
    //     }
    //     if (2 * i + 1 < n)
    //     {
    //         cout << H[2 * i + 1] << " ";
    //         qu.push(2 * i + 1);
    //     }
    // }
}
void heap::delete_heap(int *H, int n)
{
    swap(&H[1], &H[n]);
    int i = 1;
    int j = 2 * i;
    while (j < n - 1)
    {
        if (H[j + 1] > H[j]) //sibling comparision
            j++;
        if (H[i] < H[j]) //comparision with root
        {
            swap(&H[j], &H[i]);
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
}
void heap::sort(int *H)
{
    // cout << size << "  " << endl;
    for (int i = 1; i < size - 2; i++)
        delete_heap(H, size - i);
}
int main()
{
    int a[] = {0, 20, 35, 10, 25, 5, 53, 1, 90, 40, 2, 12, 34};
    int n = sizeof(a) / sizeof(a[0]);

    heap h(n);

    h.create(a);

    h.sort(a);
    // // h.delete_heap(a, 7);
    h.display(a);

    return 0;
} //every thing is well tested in this implementsations