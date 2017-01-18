#include <stdio.h>

char first[40];
char last[40];

int main(void)
{
    printf("Enter your first and last name: \n");
    scanf("%s %s", first, last);
    printf("%s, %s\n", last, first);
    return 0;
}