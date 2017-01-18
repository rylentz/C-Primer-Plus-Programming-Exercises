#include <stdio.h>

void Temps();
double f, c, k;
const double X = 5.0/9.0;
const double Y = 32.0;
const double Z = 273.16;
int main(void)
{
    printf("Enter a temperature in Fahrenheit: ");
    while(scanf("%lf", &f) == 1)
    {
        Temps();
    }
    return 0;
}

void Temps()
{
    c = X * (f - Y);
    k = c + Z;
    printf("Fahrenheit   Celcius   Kelvin\n");
    printf(" %.2lf        %.2lf     %.2lf\n", f, c, k);
    printf("Enter another temperature in Fahrenheit or a nonnumeric value to quit: ");
}