#include<stdio.h>
//calculates the harmonic mean of two numbers
#define HM(X, Y) (2/(1/(X) + 1/(Y)))

int main(void)
{
    double x, y;
    printf("Please enter two numbers: ");
    if(scanf("%lf %lf", &x, &y)==2)
        printf("The harmonic mean of %g and %g is %g.\n", x, y, HM(x, y));
    puts("Goodbye");
    return 0;
}