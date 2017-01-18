#include <stdio.h>
#include<ctype.h>
#define SIZE 10
void fetch(char * st, int n);

int main(void)
{
    char string[SIZE];
    printf("Please type a sentence. Press [enter] to indicate that you are finished.\n");
    fetch(string, SIZE);
    printf("Your first word was: %s", string);
    printf("\n");
    return 0;
}

void fetch(char * st, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        *(st+i)=getchar();
        while(isspace(*(st+i)) && i<1)
        {
            i=-1;
            continue;
        }
        if(isspace(*(st+i)) && i>=1)
            break;
    }
    
}