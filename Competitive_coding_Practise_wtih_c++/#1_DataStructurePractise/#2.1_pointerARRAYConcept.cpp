#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char **argv)
{
    int *p;
    p = (int *)(malloc(sizeof(int) * 5));
    int i = 0;
    while (i < 5)
    {
        scanf("%d", &p[i]);
        i++;
    }
    i = 0;
    while (i < 5)
    {
        printf("%d ", p[i]);
        i++;
    }
    free(p);

    // rem this
    int a[] = {1, 2, 4, 5, 6, 7};
    int *b = a;
    b = b + 2;
    cout << b[0] << endl;
    // it will return  4 rem this concept

    return 0;
}