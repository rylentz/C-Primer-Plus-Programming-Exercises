#include <stdio.h>
int critic(int i);
int main(void)
{
    int units = 0;
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
    {
        units = critic(units);
        
    }
    printf("You must have looked it up!\n");
    return 0;
}
int critic(int i)
{
    printf("No luck, my friend. Try again.\n");
    scanf("%d", &i);
    return i;
}