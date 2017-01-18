#include<stdio.h>
#define SIZE 7
void copy_arr(double ar[], double source[], int i);

int main(void)
{
    int x;
    double seven[]={1,2,3,4,5,6,7};
    double three[]={0,0,0};
    printf("The contents of seven[] are: .\n");
    for(x=0; x<SIZE; x++)
        printf("%g ", seven[x]);
    printf("\n");
    printf("The contents of three[] are: .\n");
    for(x=0; x<3; x++)
        printf("%g ", three[x]);
    printf("\n");
    copy_arr(three, &seven[2], 3);
    printf("Now the contents of three[] are: .\n");
    for(x=0; x<3; x++)
        printf("%g ", three[x]);
    printf("\n");
    return 0;
}

void copy_arr(double ar[], double source[], int i)
{
    int x;
    for(x=0; x<i; x++)
        ar[x]=source[x];
}