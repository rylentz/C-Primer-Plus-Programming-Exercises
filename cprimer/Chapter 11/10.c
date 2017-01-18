#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 40
char * s_gets(char * st, int n);
void nosp(char *string);

int main(void)
{
    char string[SIZE];
    puts("Enter a string and I'll make its spaces disappear: ");
    s_gets(string, SIZE);
    while(*string)
    {
        nosp(string);
        puts("Enter another string: ");
        s_gets(string, SIZE);
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

void nosp(char *string)
{
    int t, s;
    size_t l = strlen(string);
    char temp[l];
    for(t=0, s=0; s<l; t++, s++)
    {
        temp[t] = string[s];
        if(isspace(string[s]))
            t--;
    }
    strcpy(string, temp);
    puts(string);
}