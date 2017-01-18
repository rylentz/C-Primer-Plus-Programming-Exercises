#include<stdio.h>

int main(void)
{
    char c;
    int rep=0;
    printf("Type whatever you like and finish with # followed by ENTER: ");
    while((c=getchar())!='#')
    {
        if(c=='e')
        {
            c=getchar();
            if(c!='i')    
                continue;
            else
                rep++;
        }
    }
    printf("\n \"ei\" occurs %d times.\n", rep);
    return 0;
}