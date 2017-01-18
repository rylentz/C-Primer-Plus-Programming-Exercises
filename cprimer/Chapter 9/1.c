#include<stdio.h>

double min(double *a, double *b);

int main(void)
{
    double x, y;
    printf("Please enter two floating point numbers: ");
    scanf("%lf %lf", &x, &y);
    x=min(&x, &y);
    printf("%g is the smaller number.\n", x);
    return 0;
}

double min(double *a, double *b)
{
    double z=*a;
    if(z>*b)
        z=*b;
    return z;
}