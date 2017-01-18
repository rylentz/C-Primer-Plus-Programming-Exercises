#include<stdio.h>
#define SIZE 8
int main(void)
{
    //declare variables - 2 double arrays
    double first[SIZE], second[SIZE];
    int x, y;
    printf("Enter eight numbers for an array: ");
    //use loop to get user input - 8 integers - and put into first array
    for(x=0; x<SIZE; x++)
    {
        scanf("%lf", &first[x]);
    }
    //put sums of first array into second array
    for(x=0, y=0; x<SIZE; x++)
    {
        y += first[x];
        second[x] = y;
    }
    //use loop to print values of first array
    for(x=0; x<SIZE; x++)
        printf("%.2lf ", first[x]);
    printf("\n");
    for(x=0; x<SIZE; x++)
        printf("%.2lf ", second[x]);
    //use loop to print values of second array
    printf("\n");
    return 0;
}