#include<stdio.h>

#define RATE1 8.75
#define RATE2 9.33
#define RATE3 10.00
#define RATE4 11.20
#define OT (RATE*1.5)
#define TAX1 .15 //up to $300
#define TAX2 .2 //up to $450
#define TAX3 .25 //over $450
void Paycalc();

float hrs=0.0, gross=0.0, taxes=0.0, net=0.0, RATE;
int OPT;

int main(void)
{
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr                         b)$9.33/hr\n");
    printf("c) $10.00/hr                        d)$11.20/hr\n");
    printf("q) quit\n");
    printf("*****************************************************************\n");
    while((OPT=getchar())!=0)
    {
        switch(OPT)
        {
            case 'a' :  RATE=RATE1;
                        Paycalc(RATE);
                        break;
            case 'b' :  RATE=RATE2;
                        Paycalc(RATE);
                        break;
            case 'c' :  RATE=RATE3;
                        Paycalc(RATE);
                        break;
            case 'd' :  RATE=RATE4;
                        Paycalc(RATE);
                        break;
            case 'q' :  printf("Have a nice day.\n");
                        return 0;
            default  :  break;
        }
        printf("*****************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n");
        printf("a) $8.75/hr                         b)$9.33/hr\n");
        printf("c) $10.00/hr                        d)$11.20/hr\n");
        printf("q) quit\n");
        printf("*****************************************************************\n");
        OPT=getchar();
    }
    return 0;
}


void Paycalc()
{
    printf("How many hours did you work this week? ");
    scanf("%f", &hrs);
    if(hrs<=30)
    {
        gross=RATE*hrs;
        taxes=gross*TAX1;
    }
    else if(hrs<=40)
    {
        gross=RATE*hrs;
        taxes=300*TAX1+(gross-300)*TAX2;
    }
    else if(hrs<=45)
    {
        gross=40*RATE+(hrs-40)*OT;
        taxes=300*TAX1+100*TAX2+(hrs-40)*OT*TAX2;
    }
    else
    {
        gross=40*RATE+(hrs-40)*OT;
        taxes=300*TAX1+150*TAX2+(gross-450)*TAX3;
    }
    net=gross-taxes;
    printf("Gross pay $%.2f minus taxes $%.2f equals net pay $%.2f\n", gross, taxes, net);
}
