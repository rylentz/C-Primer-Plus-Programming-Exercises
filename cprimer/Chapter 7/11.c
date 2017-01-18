#include<stdio.h>

#define ARTICHOKES 2.05
#define BEETS 1.15
#define CARROTS 1.09
#define DISC .05
#define SHIP1 6.50
#define SHIP2 14.00
#define SHIP3 (14.00+.50*lbs)

void Discount();
void Shipping();

float lbs=0.0, ca=0.0, cb=0.0, cc=0.0, grand=0.0, discount=0.0, subtotal=0.0, shipping=0.0;
float pa=0.0, pb=0.0, pc=0.0, tpa=0.0, tpb=0.0, tpc=0.0;
int opt;

int main(void)
{
    printf("********************************************************************************************\n");
    printf("Please select the vegetable you would like to order, or enter 'q' exit the ordering process:\n");
    printf("a) Artichokes               b)Beets             c)Carrots\n");
    printf("********************************************************************************************\n");
    while((opt=getchar())!=1)
    {
        switch(opt)
        {
            case 'a' :  printf("How many pounds of artichokes would you like? ");
                        scanf("%f", &pa);
                        tpa+=pa;
                        break;
            case 'b' :  printf("How many pounds of beets would you like? ");
                        scanf("%f", &pb);
                        tpb+=pb;
                        break;
            case 'c' :  printf("How many pounds of carrots would you like? ");
                        scanf("%f", &pc);
                        tpc=pc;
                        break;
            case 'q' :  lbs=tpa+tpb+tpc;
                        ca=tpa*ARTICHOKES;
                        cb=tpb*BEETS;
                        cc=tpc*CARROTS;
                        subtotal=ca+cb+cc;
                        Discount();
                        Shipping();
                        grand=subtotal-discount+shipping;
                        goto Bill;
            default  :  break;
        }
        printf("*******************************************************************************************************\n");
        printf("Please select any additional vegetable you would like to order, or enter 'q' exit the ordering process:\n");
        printf("a) Artichokes               b)Beets             c)Carrots\n");
        printf("*******************************************************************************************************\n");
        opt=getchar();
    }
    Bill :
        printf("Cost per Pound:         $%.2f\n", subtotal/lbs);
        printf("Total Pounds Ordered:    %.2f\n", lbs);
        printf("Cost of Artichokes:     $%.2f\n", ca);
        printf("Cost of Beets:          $%.2f\n", cb);
        printf("Cost of Carrots:        $%.2f\n", cc);
        printf("Subtotal:               $%.2f\n", subtotal);
        printf("Discount:               $%.2f\n", discount);
        printf("Shipping:               $%.2f\n", shipping);
        printf("Grand Total:            $%.2f\n", grand);
    return 0;
}

void Discount()
{
    if(subtotal<100.00)
        discount=0.0;
    else
        discount=DISC*subtotal;
}

void Shipping()
{
    if(lbs<=5)
        shipping=SHIP1;
    else if(lbs<20)
        shipping=SHIP2;
    else
        shipping=SHIP3;
}