/* union intersection and difference in sorted array*/
#include <stdio.h>
#include <cstdlib>
struct array
{
    int A[5];
    int length;
};

int *merge(struct array arr1, struct array arr2)//////this is union or array
{
    int i = 0;
    int j = 0;
    int k = 0;

    static int arr3[20];
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3[k++] = arr1.A[i++];
        else if (arr1.A[i] > arr2.A[j])
            arr3[k++] = arr2.A[j++];

        else
        {
            arr3[k++] = arr2.A[j];
            j++;
            i++;
        }
    }
    for (; i < arr1.length; i++)
    {
        arr3[k++] = arr1.A[i];
    }
    for (; j < arr2.length; j++)
    {
        arr3[k++] = arr2.A[j];
    }
    // printf("%d", i);
    // printf("%d", j);

    return arr3;
}

int *intersection(struct array arr1, struct array arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;

    static int arr3[20];
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            i++;
        else if (arr1.A[i] > arr2.A[j])
            j++;

        else
        {
            arr3[k++] = arr2.A[j];
            j++;
            i++;
        }
    }
   
    return arr3;
}
int *difference(struct array arr1, struct array arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;

    static int arr3[20];
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3[k++] = arr1.A[i++];
        else if (arr1.A[i] > arr2.A[j])
            j++;

        else
        {
            
            j++;
            i++;
        }
    }
    for (; i < arr1.length; i++)
    {
        arr3[k++] = arr1.A[i];
    }
   
   
    return arr3;
}
int main()
{
    struct array arr1 = {{1, 2, 3, 5, 7}, 5};
    struct array arr2 = {{4, 5, 8, 9, 10}, 5};
    for (int i = 0; i < 5; i++)
        printf("\n%d \t\t %d\n", arr1.A[i], arr2.A[i]);
//     int *p = merge(arr1, arr2);
//  int *p = difference(arr1, arr2);
  int *p = intersection(arr1, arr2);
    printf("\nmerge array");
    for (int i = 0; i < 10; i++)
    {
        printf("\n%d \n", p[i]);
    }

    return 0;
}
