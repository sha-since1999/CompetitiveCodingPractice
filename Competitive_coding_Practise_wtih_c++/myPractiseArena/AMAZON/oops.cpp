#include <bits/stdc++.h>
#include "input.h"
using namespace std;
class solution
{
public:
    void insert(int *a, int n)
    {
        int i = n;
        int j = i / 2;
        while (j >0 and a[i] > a[j]){
            swap(a[i], a[j]);
            i = j;
            j /= 2;
        }
    }

    void deleteHeap(int *a, int n)
    {
        swap(a[n], a[1]);
        int i = 1;
        int j = 2 * i;
        while (j < n and a[j] > a[i])
        {
            if (a[j] < a[j + 1])
                j++;
            swap(a[i], a[j]);
            i = j;
            j = 2 * i;
        }
    }
    void heapSort(int *a, int n){
        for (int i = 2; i <= n; i++)
            insert(a, i);
        while(n>2)           
            deleteHeap(a, n--);
    }
    void sol()
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        heapSort(a, n);
        for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution obj;
    obj.sol();
    return 0;
}
