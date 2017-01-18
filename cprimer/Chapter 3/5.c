#include <stdio.h>
int main(void)
{
    int age;
    
    printf("How old are you? ");
    scanf("%i", &age);
    printf("You are at least %e seconds old.\n", age * 3.156E7);

    return 0;
}