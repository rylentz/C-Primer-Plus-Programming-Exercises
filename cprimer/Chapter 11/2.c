#include <stdio.h>
#include<ctype.h>
#define SIZE 41
void fetch(char * st, int n);

int main(void)
{
    char string[SIZE];
    printf("Enter up to %d charactes and I'll store them for you.\n", SIZE-1);
    puts("Press [enter] twice when you are finished.");
    fetch(string, SIZE);
    printf("You entered:\n%s\n", string);
    return 0;
}

void fetch(char * st, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        st[i]=getchar();
        if(isspace(st[i]))
            break;
    }
}