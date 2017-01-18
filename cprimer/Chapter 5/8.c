#include<stdio.h>

int main(void)
{
    int a, b, c;
    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second operand: ");
    scanf("%d", &b);
    printf("Now enter the first operand: ");
    scanf("%d", &a);
    while(a > 0)
    {
        c = a % b;
        printf("%d %% %d is %d\n", a, b, c);
        printf("Enter the next number for the first operand (<=0 to quit): ");
        scanf("%d", &a);
    }
    printf("Done\n");
    return 0;
}