#include<stdio.h>

#define RATE 10.00
#define OT (RATE*1.5)
#define TAX1 .15 //up to $300
#define TAX2 .2 //up to $450
#define TAX3 .25 //over $450

//#define //up to $400
int main(void)
{
    float hrs=0.0, gross=0.0, taxes=0.0, net=0.0;
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
        taxes=300*TAX1+(hrs-30)*RATE*TAX2;
    }
    else if(hrs<=45)
    {
        gross=40*RATE+(hrs-40)*OT;
        taxes=300*TAX1+100*TAX2+(hrs-40)*OT*TAX2;
    }
    else
    {
        gross=40*RATE+(hrs-40)*OT;
        taxes=300*TAX1+150*TAX2+(hrs-45)*OT*TAX3;
    }
    net=gross-taxes;
    printf("Gross pay $%.2f minus taxes $%.2f equals net pay $%.2f\n", gross, taxes, net);
    return 0;
}
