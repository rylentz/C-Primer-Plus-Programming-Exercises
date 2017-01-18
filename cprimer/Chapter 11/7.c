#include<stdio.h>
#include<string.h>

#define SIZE 40
#define LIM 21
char *s_gets(char * st, int n);
char *mystrncpy(char *s1, char *s2, int n);

int main(void)
{
    char string1[SIZE];
    char string2[SIZE];
    char temp1[SIZE];
    char temp2[SIZE];
    puts("Please input the first string: ");
    s_gets(string1, SIZE);
    puts("Please input the second string: ");
    s_gets(string2, SIZE);
    while((*string1+*string2))
    {
        printf("string1: %s\n", string1);
        printf("string2: %s\n", string2);
        strcpy(temp1, string1);
        strcpy(temp2, string2);
        mystrncpy(string1, string2, LIM);
        printf("mystrncpy(string1, string2, %d): %s\n", LIM, string1);
        strncpy(temp1, temp2, LIM);
        printf("strncpy(string1, sting2, %d): %s\n", LIM, temp1);
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

char *mystrncpy(char *s1, char *s2, int n)
{
    for(int i=0; i<n; i++)
        s1[i]=s2[i];
    return s1;
}
