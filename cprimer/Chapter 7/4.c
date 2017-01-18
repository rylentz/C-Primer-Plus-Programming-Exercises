#include<stdio.h>

int main(void)
{
    char c;
    int rep=0;
    printf("Type whatever you like and finish with # followed by ENTER: ");
    while((c=getchar())!='#')
    {
        if(c=='.')
        {
            c='!';
            rep++;
        }
        else if(c=='!')
        {
            printf("!");
            rep++;
        }
        printf("%c", c);
    }
    printf("\nSubstitutions=%d\n", rep);
    return 0;
}