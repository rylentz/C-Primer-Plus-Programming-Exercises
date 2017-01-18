#include<stdio.h>
#include<ctype.h>

int main(void)
{
    char c;
    int ch=0;
    printf("Type whatever you like and finish with # followed by ENTER: ");
    while((c=getchar()) != '#')
    {
        ch++;
        printf("\'%c\'=%d ", c, c);
        if(ch%8==0)
            printf("\n");
    }
    printf("\n");
    return 0;
}