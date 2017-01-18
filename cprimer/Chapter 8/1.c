#include<stdio.h>

int main(void)
{
    int count=0;
    char ch;
    printf("Type whatever you like. It could even be an entire book. Enter \"&\" to indicate you are finished:\n");
    while((ch=getchar())!='&')
    {
        if(ch!=' ' && ch!='\n' && ch!='\t')
            count++;
    }
    printf("Your input contains %d characters.\n", count);
    return 0;
} 