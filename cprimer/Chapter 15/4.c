#include<stdio.h>
#include<string.h>
#include<math.h>
#define NUM 9
void eatline(void);
char * onoff(int n, char *pb);
char * itobs(int n, char * ps);

int main(void)
{
    char bin[NUM];
    int x, y;
    printf("Enter a positive integer less than 256 and a bit position (0-7): ");
    while(scanf("%d %d", &x, &y)==2)
    {
        eatline();
        if(x<0 || x>255)
        {
            puts("The integer entered is outside of the range I specified! Learn to follow simple instructions! RAAAR!");
            break;
        }
        if(y<0 || y>7)
        {
            puts("The integer entered is outside of the range I specified! Learn to follow simple instructions! RAAAR!");
            break;
        }
        printf("%d is %s in binary and bit position %d is %s.\n", x, itobs(x, bin), y, onoff(y, bin));
        printf("Enter a positive integer less than 256 and a bit position 0-7 (q to quit): ");
    }
    puts("Buh-bye now.");
    return 0;
}
char * onoff(int n, char *pb)
{
    if(pb[7-n]=='1')
        return "on";
    else
        return "off";
}
char * itobs(int n, char * ps)
{
    int i;
    for (i = NUM-2; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0'; // assume ASCII or similar
    ps[NUM-1] = '\0';
    return ps;
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}