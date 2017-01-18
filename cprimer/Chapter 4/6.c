#include <stdio.h>
#include <string.h>

char first[40];
char last[40];

int main(void)
{
    printf("Enter your first and last name: \n");
    scanf("%s %s", first, last);
    int f = strlen(first);
    int l = strlen(last);
    printf("%s %s\n%*i %*i\n", first, last, f, f, l, l);
    printf("%s %s\n%-*i %-*i\n", first, last, f, f, l, l);
    return 0;
}