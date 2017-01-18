#include<stdio.h>
#include<ctype.h>

int main(void)
{
    char c;
    int sp=0, nl=0, ch=0;
    printf("Type whatever you like and finish with # followed by ENTER: ");
    while((c=getchar()) != '#')
    {
        ch++;
        if(c=='\n')
            nl++;
        if(c==' ')
            sp++;
    }
    ch=ch-nl-sp;
    printf("Spaces=%d Newlines=%d Characters=%d\n", sp, nl, ch);
    return 0;
}