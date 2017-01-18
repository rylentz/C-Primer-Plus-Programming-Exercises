#include<stdio.h>
#define CMPIN 2.54
#define CMPFT 30.48
#define INPFT 12.0

int main(void)
{
    float cm, feet, inches, left;
    printf("Enter a height in centimeters: ");
    scanf("%f", &cm);
    inches = cm / CMPIN;
    feet = cm / CMPFT;
    left = inches - (int) feet * INPFT;
    while(cm > 0)
    {
        inches = cm / CMPIN;
        feet = cm / CMPFT;
        left = inches - (int) feet * INPFT;
        printf("%.1f cm = %d feet, %.1f inches.\n", cm, (int) feet, left);
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%f", &cm);
    }
    printf("Bye\n");
    return 0;
}