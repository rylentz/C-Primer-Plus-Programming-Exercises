#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 60

int main(void)
{
    int num, i;
    printf("How many words would you like to enter? ");
    if (scanf("%d", &num) != 1)
    {
        puts("Number not correctly entered -- bye.");
        exit(EXIT_FAILURE);
    }
    char *p[num];
    *p=(char *)malloc(num*sizeof(char));
    if (*p == NULL)
    {
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    }
    char temp[num][MAX];
    printf("Enter %d words: ", num);
    for(i=0; i<num; i++)
    {
        scanf("%s", &*temp[i]);
    }
    for(i=0; i<num; i++)
    {
        p[i] = (char *) malloc(strlen(temp[i]));
        strcpy(p[i], temp[i]);
        puts(p[i]);
        free(p[i]);
    }
    puts("Done");

    return 0;
}

