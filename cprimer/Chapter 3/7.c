#include <stdio.h>
int main(void)
{
    float height;
    float cent = 2.54;
    
    printf("How tall are you in inches?____\b\b\b\b ");
    scanf("%f", &height);
    printf("You are %.1f centimeters tall.\n", height * cent);

    return 0;
}