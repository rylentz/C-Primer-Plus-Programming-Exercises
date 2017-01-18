#include<stdio.h>

void chline(char ch, int i, int j);

int main(void)
{
    char ch;
    int i, j;
    printf("Please enter a character and two numbers between 0 and 100, lower number first: ");
    scanf("%c %d %d", &ch, &i, &j);
    chline(ch, i, j);
    return 0;
}

void chline(char ch, int i, int j)
{
    int x;
    if(ch!='\n')
    {
        for(x=1; x<i; x++)
            printf(" ");
        for(x=i; x<=j; x++)
            putchar(ch);
            printf("\n");
    }
}
