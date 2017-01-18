#include<stdio.h>

double big(double ar[], int x);

int main(void)
{
    double array[]={19,2,3,4,5,6,77,8,10,9,5,20};
    double answer = big(array, 12);
    printf("The difference bewteen the largest element and the smallest element of the array is %g.\n", answer);
    return 0;
}

double big(double ar[], int x)
{
    int i;
    double big=ar[0];
    double small=ar[0];
    double dif;
    for(i=0; i<x; i++)
    {
        if(big<ar[i])
            big=ar[i];
        if(small>ar[i])
            small=ar[i];
        dif=big-small;
    }
    return dif;
}