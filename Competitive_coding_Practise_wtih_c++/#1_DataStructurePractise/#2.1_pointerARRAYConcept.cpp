#include<stdio.h>
#include<stdlib.h>
int main(int argc, const char** argv) {
    int *p;
    p=(int *)(malloc(sizeof(int)*5));
int i=0;
while(i<5){
    scanf("%d" ,&p[i] );
    i++;
}
i=0;
while(i<5){
printf("%d ",p[i]);
i++;}
free(p);
    return 0;
}       