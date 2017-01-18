#include <stdio.h>

#define SEC_MIN 60

int main (void)
{
    int hr, min, left;
    printf("Convert time in minutes to hours and minutes in just seconds.\n");
    printf("Enter a time in minutes (<=0 to quit):\n");
    scanf("%d", &min);
    
    while(min>0)
    {
        hr = min / SEC_MIN;
        left = min % SEC_MIN;
        printf("%d minutes is %d hours and %d minutes.\n", min, hr, left);
        printf("Enter next value (<=0 to quit):\n");
        scanf("%d", &min);
    }
    printf("Done!\n");
    return 0;
}
