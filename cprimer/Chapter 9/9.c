#include<stdio.h>

double power(double n, int p);

int main(void)
{
    double x, xpow;
    int exp;
    printf("Enter a number and the integer power to which the number will be raised. ");
    printf("Enter q to quit.\n");
    while (scanf("%lf %d", &x, &exp) == 2)
    {
        if((x==0) && (exp==0))
            printf("0 to the power of 0 is undefined, although this program will tell you that ");
        xpow = power(x,exp); // function call
        printf("%g to the power %d is %g\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");
    return 0;
}

double power(double n, int p) // function definition
{
    double pow=1;
    if(p > 0)
    {    
        pow *= n*(power(n, p-1));
    }
    if(p < 0)
    {    
        p=-p;
        pow *= n*(power(n, p-1));
        pow = 1/pow;
    }
    
    return pow; // return the value of pow
}