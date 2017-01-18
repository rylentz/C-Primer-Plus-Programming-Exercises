#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[20];
    printf("Enter your first name: \n");
    scanf("%s", name);
    int letters = strlen(name);
    printf("\"%s\"\n", name);
    printf("\"%20s\"\n", name);
    printf("\"%-20s\"\n", name);
    printf("%*s\n", letters + 3, name);
    return 0;
}