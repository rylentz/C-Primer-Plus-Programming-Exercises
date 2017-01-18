#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#define NUM 9
char * itobs(int n, char * ps);
int btoi(char * pb);

int main(int argc, char *argv[])
{
    char temp[NUM];
    int n1, n2;
    if(argc!=3)
    {
        printf("Usage: ./2 \"8-dig binary\" \"8-dig binary\"\n");
        exit(EXIT_FAILURE);
    }
    if(strlen(argv[1])!=NUM-1 || strlen(argv[2])!=NUM-1)
    {
        printf("Usage: ./2 \"8-dig binary\" \"8-dig binary\"\n");
        exit(EXIT_FAILURE);
    }
    n1=btoi(argv[1]);
    n2=btoi(argv[2]);
    printf("~ %s = %s\n", argv[1], itobs(~n1, temp));
    printf("~ %s = %s\n", argv[2], itobs(~n2, temp));
    printf("%s & %s = %s\n", argv[1], argv[2], itobs((n1&n2), temp));
    printf("%s | %s = %s\n", argv[1], argv[2], itobs((n1|n2), temp));
    printf("%s ^ %s = %s\n", argv[1], argv[2], itobs((n1^n2), temp));    
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

char * itobs(int n, char * ps)
{
    int i;
    for (i = NUM - 2; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0'; // assume ASCII or similar
    ps[NUM-1] = '\0';
    return ps;
}