#include<stdio.h>

int main(void)
{
    float x, y, z;
    printf("Give me two decimal point values, separated by a space: ");
    scanf("%f %f", &x, &y);
    do
    {
        z=(x-y)/(x*y);
        printf("(%.2f-%.2f)/(%.2f*%.2f)= %.2f\n", x, y, x, y, z);
        printf("Give me two more decimal point values, or enter q to quit: ");
    } while(scanf("%f %f", &x, &y) != 0);
    return 0;
}