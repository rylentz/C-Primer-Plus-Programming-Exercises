#include<stdio.h>
void cubed();
double x;
int main(void)
{
    printf("Give me a real number and I'll cube it for you:\n");
    scanf("%lf", &x);
    cubed();
    return 0;
}

void cubed()
{
    x = x * x * x;
    printf("%lf\n", x);
}