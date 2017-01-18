#include<stdio.h>

int Fibonacci(int n);

int main(void)
{
    int number;
    printf("Enter a number and you will receive the corresponding Fibonacci number: ");
    scanf("%d", &number);
    printf("%d\n", Fibonacci(number));
    return 0;
}

int Fibonacci(int n)
{
    int a = 0, b = 1, c, x;
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