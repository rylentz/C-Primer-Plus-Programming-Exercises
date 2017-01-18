#include<stdio.h>

int main(void)
{
    int end, count, sum;
    printf("I can sum any series of 20 integers. What number should I end with?\n");
    scanf("%d", &end);
    count = end - 20;
    sum = 0;
    
    while(count++ < end)
    sum = sum + count;
    printf("Sum = %d\n", sum);
    return 0;
}