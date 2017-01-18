#include <stdio.h>
int main(void)
{
    float h2o;
    float grams = 950.0;
    float mol = 3.0E-23;
    
    
    printf("How much water do you drink per day in quarts? ");
    scanf("%f", &h2o);
    printf("You consume about %e molecules of water per day.\n", h2o * grams / mol);

    return 0;
}