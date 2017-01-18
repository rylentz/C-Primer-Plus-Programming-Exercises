#include<stdio.h>

double big(double ar[], int x);

int main(void)
{
    double array[]={1,2,3,4,5,6,77,8,10,9,5,20};
    int answer = big(array, 12);
    printf("Index %d contains the largest element of the array.\n", answer);
    return 0;
}

double big(double ar[], int x)
{
    int i, ind;
    double big=ar[0];
    for(i=0, ind=0; i<x; i++)
        if(big<ar[i])
        {
            big=ar[i];
            ind=i;
        }
    return ind;
}