#include <stdio.h>
void to_base_n(unsigned long n, unsigned long i);

int main(void)
{
    unsigned long number, base;
    printf("Enter two integers (q to quit):\n");
    while (scanf("%lu %lu", &number, &base) == 2)
    {
        printf("Base %lu equivalent of %lu: ", base, number);
        to_base_n(number, base);
        putchar('\n');
        printf("Enter two more integers (q to quit):\n");
    }
    printf("Done.\n");
    return 0;
}

void to_base_n(unsigned long n, unsigned long i) /* recursive function */
{
    int r;
    r = n % i;
    if (n >= i)
        to_base_n(n/i, i);
    r==0 ? printf("0") : printf("%d", r);
    
    return;
}