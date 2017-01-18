#include <stdio.h>
#include<string.h>
#define SIZE 40
char *string_in(const char *s1, const char *s2);
char *s_gets(char * st, int n);

int main(void)
{
    char string1[SIZE];
    char string2[SIZE];
    char *value;
    puts("Please input the first string: ");
    s_gets(string1, SIZE);
    puts("Please input the second string: ");
    s_gets(string2, SIZE);
    while((*string1+*string2))
    {
        printf("string1: %s\n", string1);
        printf("string2: %s\n", string2);
        if((value=string_in(string1, string2)))
            printf("string1 contains string2 starting at location %p\n", value);
        else
            printf("string1 does not contain string2\n");
        puts("Please input another first string: ");
        s_gets(string1, SIZE);
        puts("Please input another second string: ");
        s_gets(string2, SIZE);
    }
    return 0;
}


char *s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
char *string_in(const char *s1, const char *s2)
{
    size_t s2len = strlen(s2);
    while(*s1)
    {
        if(*s1 == *s2)
        {
            if(!strncmp(s1, s2, s2len))
                return (char *)s1;
        }
        s1++;
    }
    return 0;
}