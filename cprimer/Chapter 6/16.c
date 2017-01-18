#include<stdio.h>

int main(void)
{
    const float base = 100.0;
    float daph = base, deir = base;
    int x = 0;
    printf("Daphne      Deirdre      Year\n");
    printf("$100.00     $100.00      0\n");
    do
    {
        daph = daph+base*.1;
        deir = deir*1.05;
        x++;
        printf("$%.2f     $%.2f      %d\n", daph, deir, x);
    } while(deir<daph);   
    return 0;
}