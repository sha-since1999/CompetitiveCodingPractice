#include <stdio.h>
#include <cstdlib>
#include <math.h>

struct array
{
    int *A;
    int size;
    int length;
};

int del(struct array *, int);
int add(struct array *, int);
void display(struct array *);
int insert(struct array *, int, int);
int lenear_search(struct array *, int);
int binary_search(struct array *, int);
int max(struct array);
int min(struct array);
void set(struct array *, int, int);
int get(struct array *, int);
void lshift(struct array *);
void rshift(struct array *);
void lrotate(struct array *);
void rrotate(struct array *);
void reverse(struct array *);
int sum(struct array);

int main()
{
    int key;
    int index;
    int ch;
    struct array *arr;
    arr = (struct array *)malloc(sizeof(struct array));
    printf("welcome now create array desired size in heap----:put size of array");
    scanf("%d", &arr->size);
    arr->A = (int *)malloc(sizeof(int) * arr->size);
    arr->length = 0;
    do
    {
        printf(" \n /******----------0000---------******/");
        printf("\n1.) Add element to the array");
        printf("\n2.) dislay array element ");

        printf("\n3.) delate array element ");

        printf("\n4.) insert array element ");

        printf("\n5.) lenear search  array element");
        printf("\n6.) binary array element ");

        printf("\n7.) find max array element ");

        printf("\n8.) find min array element ");

        printf("\n9.) set ");
        printf("\n10.) get ");
        printf("\n11.) reverse an array ");

        printf("\n12.) left shift an array  ");

        printf("\n13.) rigth shift an array");

        printf("\n14.) left rotate an array");

        printf("\n15.) right rotate an array");

        printf("\n16.) find sum of array element");

        printf("\n17.) find average of array elment");
        printf(" \n select opration to perform on array\n");
        scanf("\n%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nenter key ");
            scanf("\n%d", &key);
            add(arr, key);
            break;

        case 2:
            display(arr);
            break;
        case 3:
            printf("\nenter key ");

            scanf("\n%d", &key);
            del(arr, key);

            break;

        case 4:
            printf("\nenter KEY and INDEX");
            scanf("\n%d %d", &key, &index);
            insert(arr, key, index);
            break;

        case 5:
            printf("enter key ");
            scanf("\n%d", &key);
            printf("/n leanear search result:-> %d ", lenear_search(arr, key));

            break;

        case 6:
            printf("enter key ");
            scanf("\n%d", &key);
            printf("\n binary search result:-> %d", binary_search(arr, key));
            break;

        case 7:
            max(*arr);
            break;
        case 8:
            min(*arr);
            break;
        case 9:
            printf("enter key and index");
            scanf("\n%d %d", &key, &index);
            set(arr, key, index);
            break;
        case 10:
            printf("enter index  ");
            scanf("\n%d", &index);
            get(arr, index);
            break;
        case 11:
            reverse(arr);
            break;
        case 12:
            lshift(arr);
            break;
        case 13:
            rshift(arr);
            break;
        case 14:
            lrotate(arr);
            break;
        case 15:
            rrotate(arr);
            break;
        case 16:
            printf("\nsum of array element = %d", sum(*arr));

            break;
        case 17:
            printf("\naverage of array element = %d", sum(*arr) / arr->length);
            break;
        default:
            printf("\n <----please select correct input----> \n");
        }

    } while (ch != -1);

    free(arr->A);
    free(arr);

    return 0;
}
void display(struct array *arr)
{
    printf("\n");
    for (int i = 0; i < arr->length; i++)
    {
        printf("\t%d", arr->A[i]);
    }
    printf("\n");
}
int add(struct array *arr, int x)
{
    arr->A[arr->length] = x;
    arr->length++;
    return 1;
}
int del(struct array *arr, int x)
{

    // int index= lenear_search(arr,x);

    int index = binary_search(arr, x);
    int i;
    for (i = index; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }

    arr->length--;
    return 1;
}
int insert(struct array *arr, int x, int index)
{
    for (int i = arr->length; i >= index; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = x;
    arr->length++;

    return 1;
}

void swap(int *arr1, int *arr2)
{
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}
int lenear_search(struct array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            swap(&arr->A[i], &arr->A[i - 1]); // in move to head  optimise lenear search swap with 0 index
            return i - 1;
        }
    }

    return -1;
}

int binary_search(struct array *arr, int key)
{
    int lowest_index = 0;
    int highest_index = arr->length - 1;
    while (lowest_index <= highest_index)
    {
        int mid = floor((lowest_index + highest_index) / 2);
        if (arr->A[mid] == key)
            return mid;
        else
        {
            if (key > arr->A[mid])
            {
                lowest_index = mid + 1;
            }
            else
            {
                highest_index = mid - 1;
            }
        }
    }
    return -1;
}
int get(struct array *arr, int index)
{
    printf("\n\n");
    if (index >= 0 && index < arr->length)
    {
        printf("%d", arr->A[index]);
        return arr->A[index];
    }

    return -1;
}
void set(struct array *arr, int key, int index)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = key;
}
int min(struct array arr)
{
    int key = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] < key)
            key = arr.A[i];
    }
    printf("\n%d", key);
    return key;
}
int max(struct array arr)
{
    int key = 0;

    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > key)
        {
            key = arr.A[i];
        }
    }
    printf("\n%d", key);
    return key;
}

void lshift(struct array *arr)
{
    int i;
    for (i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[i] = 0;
    display(arr);
}
void rshift(struct array *arr)
{
    int i;
    for (i = arr->length - 1; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[i] = 0;
    display(arr);
}

void rrotate(struct array *arr)
{
    int temp = arr->A[0], i;
    for (i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[i] = temp;
    display(arr);
}

void lrotate(struct array *arr)
{
    int temp = arr->A[arr->length - 1];
    int i;
    for (i = arr->length - 1; i >= 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[i + 1] = temp;
    display(arr);
}
void reverse(struct array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; j > i; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
    display(arr);
}
int sum(struct array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}
