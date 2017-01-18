#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100
char * s_gets(char * st, int n);
char *lower(char *st);
char *upper(char *st);

int main(int argc, char *argv[])
{
    char str[SIZE];
    printf("Enter some input: ");
    s_gets(str, SIZE);
    
    if(argc == 1)
        puts(str);
    else if(argc == 2)
    {
        if(strcmp(argv[1], "-u")==0)
        {
            upper(str);
            printf("\n");
        }
        else if(strcmp(argv[1], "-l")==0)
        {
            lower(str);
            printf("\n");
        }
        else if(strcmp(argv[1], "-p")==0)
            puts(str);
        else
            puts(str);
    }
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

char *lower(char *st)
{
    int i = 0;
    while(st[i])
    {
        putchar(tolower(st[i]));
        i++;
    }
    return 0;
}

char *upper(char *st)
{
    int i = 0;
    while(st[i])
    {
        putchar(toupper(st[i]));
        i++;
    }
    return 0;
}