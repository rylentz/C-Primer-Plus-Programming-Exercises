#include<stdio.h>
static int x=0;
int times(void);

int main(void)
{
    int i;
    printf("Choose 1 to run the function times() or 2 to quit: ");
    scanf("%d", &i);
    while(i)
    {
        if(i==1)
        {
            printf("The function times() has been run a total of %d time(s).\n", times());
            printf("Choose 1 to run the function times() again or 2 to quit: ");
            scanf("%d", &i);
        }
        if(i==2)
        {
            puts("Buh-bye.");
            break;
        }
    }
    return 0;
}

int times(void)
{
    x++;
    return x;
}