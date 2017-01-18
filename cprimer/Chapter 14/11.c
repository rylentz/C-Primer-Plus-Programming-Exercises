#include<stdio.h>
#include<math.h>
#define NUM 10
void transform(double source[], double target[], int n, double (*fun)());
double Fibonacci(double n);
double rando(double n);

int main(void)
{
    int i;
    double source[NUM]={0,1,2,3,4,5,6,7,8,9};
    double target[NUM];
    transform(source, target, NUM, sin);
    puts("Contents of target[NUM]:");
    for(i=0;i<NUM;i++)
        printf("%g ", target[i]);
    printf("\n");
    transform(source, target, NUM, cos);
    puts("Contents of target[NUM]:");
    for(i=0;i<NUM;i++)
        printf("%g ", target[i]);
    printf("\n");
    transform(source, target, NUM, Fibonacci);
    puts("Contents of target[NUM]:");
    for(i=0;i<NUM;i++)
        printf("%g ", target[i]);
    printf("\n");
    transform(source, target, NUM, rando);
    puts("Contents of target[NUM]:");
    for(i=0;i<NUM;i++)
        printf("%g ", target[i]);
    printf("\n");
    return 0;
}

void transform(double source[], double target[], int n, double fun())
{
    int i;
    for(i=0; i<n; i++)
    {
        target[i]=fun(source[i]);
    }
    
}
double Fibonacci(double n)
{
    double a = 0, b = 1, c, x;
    if(n==0)
        return n;
    for(x = 2; x <= n; x++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
double rando(double n)
{
    n=(n+n)*n-n;
    return n;
}