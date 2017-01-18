#include<stdio.h>

void larger_of(double *x, double *y);

int main(void)
{
    double x, y;
    printf("Please enter two floating point numbers: ");
    scanf("%lf %lf", &x, &y);
    printf("Thanks. x = %g and y = %g.\n", x, y);
    larger_of(&x, &y);
    printf("The greater value is %g. Now x = %g and y = %g.\n", x, x, y);
    return 0;
}

void larger_of(double *x, double *y)
{
    double max=*x;
    if(max<*y)
        *x = *y;
    else
        *y = *x;
}