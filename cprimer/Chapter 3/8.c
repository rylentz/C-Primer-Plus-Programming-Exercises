#include <stdio.h>
int main(void)
{
    float c;
    
    printf("Enter an amount in cups:____\b\b\b\b");
    scanf("%f", &c);
    float p = c / 2;
    float o = c * 8;
    float T = o * 2;
    float t = T * 3;
    printf("%.2f cups equals:\n", c);
    printf("\t Pints: %.2f\n", p);
    printf("\t Ounces: %.2f\n", o);
    printf("\t Tablespoons: %.2f\n", T);
    printf("\t Teaspoons: %.2f\n", t);

    return 0;
}