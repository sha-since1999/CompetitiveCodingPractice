#include <bits/stdc++.h>
using namespace std;
const int N = 3;
const int M = 3;
struct doubleArray
{
    int A[N][M];
};
doubleArray print(doubleArray arr);

// int **getarray(int N, int M)
// {
//   int **arr = new int *[N];
//   for (int i = 0; i < N; i++)
//   {
//     arr[i] = new int[M];
//     for (int j = 0; j < M; j++)
//     {
//       arr[i][j] = i + j;
//     }
//   }
//   return arr;
// }

// void printArr(int **arr, int N, int M)
// {
//   for (int i = 0; i < N; i++)
//   {
//     for (int j = 0; j < M; j++)
//     {
//       cout << arr[i][j];
//     }
//     cout << endl;
//   }
// }

int main()
{

    // int **arr;
    // arr = getarray(3, 3);
    // printArr(arr, 3, 3);

    /* secont method of passing 2Darray using structure*/
    doubleArray arr;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr.A[i][j] = i + j;
        }
    }
    doubleArray arr2 = print(arr);
    cout << "reprint array after returning from function" << endl;
    print(arr2);
    return 0;
}
doubleArray print(doubleArray arr)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr.A[i][j];
        }
        cout << endl;
    }
    return arr;
}