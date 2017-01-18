#include<stdio.h>

void inorder(double *x, double *y, double *z);

int main(void)
{
    double a, b, c;
    printf("Please enter three floating point numbers and I will arrange them in order for you: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    inorder(&a, &b, &c);
    printf("Low: %g   Mid: %g   High: %g\n", a, b, c);
    return 0;
}

void inorder(double *x, double *y, double *z)
{
    double low, mid, high;
    if(*x<*y && *x<*z)
    {
        low=*x;
        if(*y<*z)
        {
            mid=*y;
            high=*z;
        }
        else
        {
            mid=*z;
            high=*y;
        }
    }
    if(*y<*x && *y<*z)
    {
        low=*y;
        if(*x<*z)
        {
            mid=*x;
            high=*z;
        }
        else
        {
            mid=*z;
            high=*x;
        }
    }
    if(*z<*x && *z<*y)
    {
        low=*z;
        if(*x<*y)
        {
        mid=*x;
        high=*y;
        }
        else
        {
            mid=*y;
            high=*x;
        }
    }
    *x=low;
    *y=mid;
    *z=high;
}
