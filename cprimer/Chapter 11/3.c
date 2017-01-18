#include <stdio.h>
#include<ctype.h>
#define SIZE 100
void fetch(char * st);

int main(void)
{
    char string[SIZE];
    printf("Please type a sentence. Press [enter] to indicate that you are finished.\n");
    fetch(string);
    printf("Your first word was: %s\n", string);
    return 0;
}

void fetch(char * st)
{
    int i;
    for(i=0; *st!='\0'; i++)
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