#include<stdio.h>
#include<stdlib.h>
double power(double n, int p);

int main(int argc, char *argv[])
{
    if(argc!=3)
        puts("Please enter two integers following the function call in the command line.");
    double pow = power(atof(argv[1]), atoi(argv[2]));
    printf("%g to the power of %d is %g\n", atof(argv[1]), atoi(argv[2]), pow);
    return 0;
}

double power(double n, int p) // function definition
{
    double pow = 1;
    int i;
    if(n==0 && p==0)
        printf("0 to the power of 0 is undefined, although this program will tell you that ");
    for (i = 1; ((p > 0) || (p < 0)) && ((i <= p) || (i <=-p)); i++)
        pow *= n;
    if(p<0)
        pow=1/pow;
    return pow; // return the value of pow
}