#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100
char * s_gets(char * st, int n);

int main(void)
{
    char st[SIZE];
    int i, isword=0, words=0, ucl=0, lcl=0, punc=0, dig=0;
    puts("Enter some input and I will analyze it for you: ");
    s_gets(st, SIZE);
    for(i=0; i<strlen(st); i++)
    {
        if(!isspace(st[i]) && !isword)
        {
            isword=1;
            words++;
        }    
        if(isspace(st[i]) && isword)
            isword=0;
        if(isupper(st[i]))
            ucl++;
        if(islower(st[i]))
            lcl++;
        if(ispunct(st[i]))
            punc++;
        if(isdigit(st[i]))
            dig++;
    }
    printf("Your input contains %d words, %d uppercase letters, ", words, ucl);
    printf("%d lowercase letters, %d puncuation characters, and %d digits.\n", lcl, punc, dig);
    return 0;
}

char * s_gets(char * st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else 
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}