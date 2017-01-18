#include<stdio.h>
#include<stdbool.h>

void Prime();
unsigned long num, div;
bool isPrime;
int main(void)
{
    printf("Please enter a positive integer for analysis (enter q to quit): ");
    while (scanf("%lu", &num) == 1)
    {
        printf("The following prime numbers are less than or equal to %lu: ", num);
        Prime();
        while(--num > 1)
            Prime();
        printf("\nPlease enter another positive integer for analysis (enter q to quit): ");
    }
    printf("Program complete. Goodbye.\n");
}

void Prime()
{
    for (div = 2, isPrime = true; (div * div) <= num; div++)
    {
        if (num % div == 0)
            isPrime= false; // number is not prime
    }
    if (isPrime)
        printf("%lu ", num);
}