#include<stdio.h>
#include<string.h>
#include<limits.h>
void rotate(char *bin, int x);
char * itobs(int n, char * ps);
void show_bstr(const char * str);
void eatline(void);
const static int size = CHAR_BIT * sizeof(int);

int main(void)
{
   char bin[size];
    int x, y;
    printf("Enter a positive integer and the number of bits you'd like the binary form of the integer shifted: ");
    while(scanf("%d %d", &x, &y)==2)
    {
        eatline();
        itobs(x, bin);
        printf("In binary, %d is: ", x);
        show_bstr(bin);
        printf("\n");
        rotate(bin, y);
        printf("Here is %d shifted %d positions to the left: ", x, y);
        show_bstr(bin);
        printf("'\n");
        printf("Enter a positive integer and the number of bits you'd like the binary form of the integer shifted: ");
    }
    puts("Buh-bye now.");
    return 0;
}

void rotate(char *bin, int n)
{
    int i;
    char temp[size];
    for(i=0; i<size; i++)
        temp[i]=bin[i];
    for(i=0; i<size; i++)
    {
        if((i+n)<=size-1)
            bin[i]=bin[i+n];
        else
            bin[i]=temp[i+n-size];
    }
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
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}