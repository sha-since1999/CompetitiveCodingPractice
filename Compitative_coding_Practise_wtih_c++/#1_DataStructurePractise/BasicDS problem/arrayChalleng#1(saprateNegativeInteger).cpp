/*separate negative to one side in array*/

#include <stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int *seprate_negative(int *a)
{
    int i = 0;
    int j = 15;
    while (i < j)
    {
        while (a[i] < 0)
            i++;
        while (a[j] > 0)
            j--;
            if(i<j)
                swap(&a[i],&a[j]);
    }
    return a;
}
int main()
{
    int a[] = {2, 5, -3, 8 -7, 9, 4, -5, -1, 23, 1, 223, 234, 32, -5, -1, 3};
for (int i = 0; i < 16;i++)
    {
        printf("\t%d",a[i]);
    }
    printf("\n");
    int *p=seprate_negative(a);
    for (int i = 0; i < 16;i++)
    {
        printf("\t%d",p[i]);
    }

        return 0;
}