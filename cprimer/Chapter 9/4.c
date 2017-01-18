#include<stdio.h>

double harmony(double x, double y);
double z;
int main(void)
{
    double i, j;
    printf("Please enter two floating point numbers: ");
    scanf("%lf %lf", &i, &j);
    harmony(i, j);
    printf("The harmonic mean of %g and %g is %g.\n", i, j, z);
    return 0;
}

double harmony(double x, double y)
{
    z = 2/(1/x + 1/y);
    return z;
}
