#include<stdio.h>

int main(void)
{
    const float base = 1000000.00, deduct = 100000.00;
    float joe = base;
    int x = 0;
    printf("Joe               Year\n");
    printf("$100000000.00      0\n");
    do
    {
        joe = joe*1.08;
        joe = joe - deduct;
        x++;
        printf("$%.2f         %d\n", joe, x);
    } while(joe>0);   
    return 0;
}