#include<stdio.h>
#include<ctype.h>

char get_first(void);

int main(void)
{
    int ch;
    printf("Type anything you like. Start with a space or tab. I will let you know what the first non-whitespace character is.\n");
    ch=get_first();
    return 0;
}

char get_first(void)
{
    int ch;
    ch=getchar();
    if(isspace(ch)==0)
        printf("%c\n", ch);

    return 0;
}