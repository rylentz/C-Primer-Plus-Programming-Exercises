#include<stdio.h>
void calc();
float x, y, z;
int main(void)
{
    printf("Give me two decimal point values, separated by a space: ");
    scanf("%f %f", &x, &y);
    do
    {
        calc();
        printf("(%.2f-%.2f)/(%.2f*%.2f)= %.2f\n", x, y, x, y, z);
        printf("Give me two more decimal point values, or enter q to quit: ");
    } while(scanf("%f %f", &x, &y) != 0);
    return 0;
}

void calc()
{
    z=(x-y)/(x*y);
}