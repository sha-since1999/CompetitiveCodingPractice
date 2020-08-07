#include<stdio.h>
#include <cstdlib>
int main(int argc, const char** argv) {
int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
for(int i=0; i<3;i++)
{
    for (int j=0; j < 3; j++)
    {
        printf("%d  ",a[i][j]);
    }
    printf("\n");
} 
printf("\n 2d array using single pointer*******\n");

int *p[3];

p[0]=(int*)malloc(3*(sizeof(int)));
p[1]=(int*)malloc(3*(sizeof(int)));
p[2]=(int*)malloc(3*(sizeof(int)));
for(int i=0; i<3;i++)
{
    for (int j=0; j < 3; j++)
    {
        printf("%d  ",p[i][j]);
    }
    printf("\n");
} 


printf("\n 2d array using double pointer****\n");




int **q;
q=(int **)malloc(sizeof(int)*3);
q[0]=(int*)malloc(sizeof(int)*3);
q[1]=(int*)malloc(sizeof(int)*3);
q[2]=(int*)malloc(sizeof(int)*3);
for(int i=0; i<3;i++)
{
    for (int j=0; j < 3; j++)
    {
        printf("%d  ",q[i][j]);
    }
    printf("\n");
} 

    return 0;
}