#include <stdio.h>
#include <float.h>

int main(void)
{
    double d = 1.0/3.0;
    float f = 1.0/3.0;
    printf("Double: %.4f\nDouble: %.12f\nDouble: %.16f\n", d, d, d);
    printf("Float: %.4f\nFloat: %.12f\nFloat: %.16f\n", f, f, f);
    printf("FLT_DIG: %i\n", FLT_DIG);
    printf("DBL_DIG: %i\n", DBL_DIG);
}