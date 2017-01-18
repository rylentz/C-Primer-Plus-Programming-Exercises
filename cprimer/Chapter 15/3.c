#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<limits.h>
char * itobs(int n, char * ps);
void eatline(void);
int ison(char *pb);
void show_bstr(const char * str);

int main(void)
{
    int x;
    const static int size = CHAR_BIT * sizeof(int);
    char bin[size];
    printf("Enter an integer and I'll convert it to binary and tell you how many of its bits are \"on\": ");
    while(scanf("%d",&x))
    {
        eatline();
        itobs(x, bin);
        printf("%d is ",  x); 
        show_bstr(bin);
        printf(" in binary and has %d bit(s) turned \"on\".\n", ison(bin));
        printf("Enter another integer or enter q to quit: ");
    }
    puts("Buh-bye.");
    return 0;
}

char * itobs(int n, char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for (i = size-1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0'; // assume ASCII or similar
    ps[size] = '\0';
    return ps;
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
int ison(char *pb)
{
    int i=0, count=0;
    const static int size = CHAR_BIT * sizeof(int);
    while(i<size)
        if(pb[i++]=='1')
            count++;
    return count;
}
void show_bstr(const char * str)
{
    int i = 0;
    while (str[i]) /* not the null character */
    {
        putchar(str[i]);
        if(++i % 4 == 0 && str[i])
            putchar(' ');
    }
}