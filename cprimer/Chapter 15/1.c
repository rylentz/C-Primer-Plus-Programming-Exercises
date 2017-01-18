#include<stdio.h>
#include<string.h>
#include<math.h>
#define NUM 9
char * s_gets(char * st, int n);
int btoi(char * pb);

int main(void)
{
    char bin[NUM];
    char *pb;
    int x;
    printf("Enter an 8-digit binary number and I'll convert it to a decimal number for you ([enter] to quit): ");
    while((pb=s_gets(bin, NUM)))
    {
        if(bin[0]=='\0')
        {
            printf("Buh-bye.\n");
            return 0;
        }
        else
        {
            x=btoi(pb);
            printf("The decimal equivalent of %s is %d\n", bin, x);
            printf("Enter another 8-digit binary number and I'll convert it to a decimal number for you ([enter] to quit): ");
        }
    }
    
    return 0;
}

int btoi(char * pb)
{
    int sum=0, i;
    for(i=NUM-2; i>=0; i--)
    {
        if(pb[i]=='1')
            sum+=(int)pow(2,(7-i));
    }
    return sum;
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}