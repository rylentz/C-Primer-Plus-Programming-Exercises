#include <stdio.h>
#include<string.h>
#define SIZE 100
#define CH 'x'
char *s_gets(char * st, int n);
char *retloc(char * st, char ch);

int main(void)
{
    char *ret;
    char string[SIZE];
    printf("Please type a sentence. Press [enter] to indicate that you are finished.\n");
    while(*s_gets(string, SIZE))
    {
        printf("You typed: %s\n", string);
        ret = retloc(string, CH);
        printf("The first occurence of %c was at location: (nil if no \"x\" was present) %p\n", CH, ret);
    printf("Please type another sentence. Press [enter] to indicate that you are finished.\n");
    }
    return 0;
}

char *s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

char *retloc(char * st, char ch)
{
    int i=0;
    for(i=0; i<strlen(st); i++)
    {
        if(*(st+i)==ch)
            return (st+i);
        else
            continue;
    }
    return 0;
}