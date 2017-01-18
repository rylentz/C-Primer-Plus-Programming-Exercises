#include<stdio.h>

#define SIZE 6

void addncopy(int a1[], int a2[], int a3[], int i);
void printar(int array[]);

int main(void)
{
    int one[] = {1,2,3,4,5,6};
    int two[] = {6,5,4,3,2,1};
    int three[SIZE] = {0};
    printf("The contents of one[] are:\n");
    printar(one);
    printf("The contents of two[] are:\n");
    printar(two);
    printf("The contents of three[] are:\n");
    printar(three);
    printf("one[] + two[] = three[] \n");
    addncopy(one, two, three, SIZE);
    printf("Now the contents of three[] are:\n");
    printar(three);
    return 0;
}

void addncopy(int a1[], int a2[], int a3[], int i)
{
    int x;
    for(x=0; x<i; x++)
        a3[x] = a1[x]+a2[x];
}

void printar(int array[])
{
    int x;
    for(x=0; x<SIZE; x++)
        printf("%d ", array[x]);
    printf("\n");
}