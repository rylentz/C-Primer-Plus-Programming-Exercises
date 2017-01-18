#include<stdio.h>

#define SINGLE 17850
#define HOH 23900
#define MJ 29750
#define MS 14875
#define TAX1 .15 
#define TAX2 .28

void Taxcalc();

float inc=0.0, tax=0.0, status;
int OPT;

int main(void)
{
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to your tax status:\n");
    printf("1) Single                           2)Head of Household\n");
    printf("3) Married, Joint                   4)Married, Separate\n");
    printf("5) Quit\n");
    printf("*****************************************************************\n");
    while((OPT=getchar())!=0)
    {
        switch(OPT)
        {
            case '1' :  status=SINGLE;
                        Taxcalc(status);
                        break;
            case '2' :  status=HOH;
                        Taxcalc(status);
                        break;
            case '3' :  status=MJ;
                        Taxcalc(status);
                        break;
            case '4' :  status=MS;
                        Taxcalc(status);
                        break;
            case '5' :  printf("Have a nice day.\n");
                        return 0;
            default  :  break;
        }
        printf("*****************************************************************\n");
        printf("Enter the number corresponding to your tax status:\n");
        printf("1) Single                           2)Head of Household\n");
        printf("3) Married, Joint                   4)Married, Separate\n");
        printf("5) Quit\n");
        printf("*****************************************************************\n");
        OPT=getchar();
    }
    return 0;
}


void Taxcalc()
{
    printf("What is your taxable income? ");
    scanf("%f", &inc);
    if(inc<=status)
    {
        tax=TAX1*inc;
    }
    else
    {
        tax=(TAX1*status)+(TAX2*(inc-status));
    }
   
    printf("You owe $%.2f in taxes.\n", tax);
}