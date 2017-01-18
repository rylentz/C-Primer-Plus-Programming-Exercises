#include<stdio.h>
#include<ctype.h>

void Add();
void Sub();
void Mul();
void Div();
double Getnum1(void);
double Getnum2(void);
double Getnum1div(void);
double Getnum2div(void);

double num1, num2, answer;
int opt;

int main(void)
{
    printf("*****************************************************************\n");
    printf("Please enter the operation of your choice:\n");
    printf("a) Addition                         s)Subtraction\n");
    printf("m) Multiplication                   d)Division\n");
    printf("q) Quit\n");
    printf("*****************************************************************\n");
    while((opt=getchar())!=0)
    {
        switch(opt)
        {
            case 'a' :  Add();
                        break;
            case 's' :  Sub();
                        break;
            case 'm' :  Mul();
                        break;
            case 'd' :  Div();
                        break;
            case 'q' :  printf("Buh-bye.\n");
                        return 0;
            default  :  break;
        }
        printf("*****************************************************************\n");
        printf("Please enter the operation of your choice:\n");
        printf("a) Addition                         s)Subtraction\n");
        printf("m) Multiplication                   d)Division\n");
        printf("q) Quit\n");
        printf("*****************************************************************\n");
        opt=getchar();
    }
    return 0;
}

void Add()
{
    Getnum1();
    Getnum2();
    answer=num1+num2;
    printf("%g + %g = %g\n", num1, num2, answer);
}

void Sub()
{
    Getnum1();
    Getnum2();
    answer=num1-num2;
    printf("%g - %g = %g\n", num1, num2, answer);
}

void Mul()
{
    Getnum1();
    Getnum2();
    answer=num1*num2;
    printf("%g * %g = %g\n", num1, num2, answer);
}

void Div()
{
    Getnum1();
    Getnum2();
    Getnum2div();
    answer=num1/num2;
    printf("%g / %g = %g\n", num1, num2, answer);
}

double Getnum1(void)
{
    char ch;
    printf("Enter first number: ");
    while(scanf("%lf", &num1) != 1)
    {
        while((ch=getchar()) != '\n')
            putchar(ch);
        printf(" is not a number.\n");
        printf("Please enter a number, such as 4.7, -3.9E9, or 6: \n");
    }
    return num1;
}

double Getnum2(void)
{
    char ch;
    printf("Enter second number: ");
    while(scanf("%lf", &num2) != 1)
    {
        while((ch=getchar()) != '\n')
            putchar(ch);
        printf(" is not a number.\n");
        printf("Please enter a number, such as 4.7, -3.9E9, or 6: \n");
    }
    return num2;
}

double Getnum2div(void)
{
    while(num2==0)
    {
        printf("Cannot dvide by 0. Please enter a number other than 0: ");
        scanf("%lf", &num2);
        continue;
    }
    return num2;
}