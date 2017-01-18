#include<stdio.h>

#define DPW 7

int main(void)
{
    int days, weeks, left;
    printf("I can convert a given number of days into weeks and days. Just give me a number of days!\n");
    printf("(To keep things interesting, I'd recommend a number greater than 7. To quit, simply enter a number <=0.)\n");
    scanf("%d", &days);
    
    while(days > 0)
    {
        weeks = days / DPW;
        left = days % DPW;
        printf("%d days are %d weeks, %d days.\n", days, weeks, left);
        printf("Enter another value (<=0 to quit):\n");
        scanf("%d", &days);
    }
    return 0;   
}