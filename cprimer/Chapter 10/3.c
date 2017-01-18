#include<stdio.h>

int big(int ar[], int x);

int main(void)
{
    int array[]={1,2,3,4,5,6,7,8,10,9,5,20};
    int answer = big(array, 12);
    printf("%d is the largest element of the array.\n", answer);
    return 0;
}

int big(int ar[], int x)
{
    int i;
    int big=ar[0];
    for(i=0; i<x; i++)
        if(big<ar[i])
            big=ar[i];
    return big;
}