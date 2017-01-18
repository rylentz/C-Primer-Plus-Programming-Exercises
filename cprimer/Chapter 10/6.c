#include<stdio.h>

void rev(double ar[], int x);
#define SIZE 12
int main(void)
{
    int x;
    double array[]={1,2,3,4,5,6,77,8,10,9,5,20};
    printf("The contents of array[] are: .\n");
    for(x=0; x<SIZE; x++)
        printf("%g ", array[x]);
    rev(array, SIZE);
    printf("Now the contents of array[] are: .\n");
    for(x=0; x<SIZE; x++)
        printf("%g ", array[x]);
    printf("\n");
    return 0;
}

void rev(double ar[], int x)
{
    int u, d;
    double rev[SIZE];
    for(u=0, d=x-1; u<x && d>=0; u++, d--)
        rev[d]=ar[u];
    for(u=0; u<x; u++)
        ar[u]=rev[u];
}