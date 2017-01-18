#include<stdio.h>
#include<string.h>
#define SIZE 40
char * s_gets(char * st, int n);
void rev(char *string);

int main(void)
{
    char string[SIZE];
    puts("Enter a string and I'll reverse it for you: ");
    s_gets(string, SIZE);
    while(*string)
    {
        rev(string);
        puts(string);
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

void rev(char *string)
{
    size_t l = strlen(string);
    int i;
    char temp[l];
    for(i=0; i<l; i++)
        temp[i] = string[l-1-i];
    strcpy(string, temp);
    string[l] = '\0';
}