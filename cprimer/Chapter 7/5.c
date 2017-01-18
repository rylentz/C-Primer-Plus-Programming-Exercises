#include<stdio.h>

int main(void)
{
    char c;
    int rep=0;
    printf("Type whatever you like and finish with # followed by ENTER: ");
    while((c=getchar())!='#')
    {
        switch(c)
        {
            case '.':
                c='!';
                rep++;
                break;
            case '!':    
                printf("!");
                rep++;
                break;
        }
        printf("%c", c);
    }
    printf("\nSubstitutions=%d\n", rep);
    return 0;
}