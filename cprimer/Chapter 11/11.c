#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 40
#define NUM 10
char * s_gets(char * st, int n);
void stsrt(char *strings[], int num);
void length(char *string[], int num);
void word1(char *strings[], int num);
int fetch(char *st);


int main(void)
{
    int choice;
    int ct=0;
    int i;
    char input[NUM][SIZE];
    char *ptstr[NUM];
    printf("Please enter up to %d strings. Press [enter] at the start of a new line to stop.\n", NUM);
    while (ct < NUM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];
        ct++;
    }
    puts("Please choose from the following list:");
    puts("1) Print strings                           2) Print strings in ASCII order of first character");
    puts("3) Print strings in order of length        4) Print strings in order of the length of the first word");
    puts("5) Quit");
    while((choice = getchar()))
    {
        switch(choice)
        {
            case '1' :  for(i=0; i<ct; i++)
                            puts(input[i]);
                        break;
            case '2' :  stsrt(ptstr, ct);
                        break;
            case '3' :  length(ptstr, ct);
                        break;
            case '4' :  word1(ptstr, ct);
                        break;
            case '5' :  puts("Have a nice day.");
                        return 0;
            default  :  break;
        }
        puts("Please choose from the following list:");
        puts("1) Print strings                           2) Print strings in order of first letter");
        puts("3) Print strings in order of length        4) Print strings in order of the length of the first word");
        puts("5) Quit");
        choice = getchar();
    }
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

void stsrt(char *strings[], int num)
{
    char *temp;
    int top, seek, k;
    for (top = 0; top < num-1; top++)
    {
        for (seek = top + 1; seek < num; seek++)
        {
            if (strcmp(strings[top],strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    }        
    puts("\nSorted by first character:\n");
    for (k = 0; k < num; k++)
        puts(strings[k]);
}

void length(char *strings[], int num)
{
    char *temp;
    int top, seek, k;
    for (top = 0; top < num-1; top++)
    {
        for (seek = top + 1; seek < num; seek++)
        {
            if ((strlen(strings[top]))>(strlen(strings[seek])))
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    }        
    puts("\nSorted by string length:\n");
    for (k = 0; k < num; k++)
        puts(strings[k]);
}

void word1(char *strings[], int num)
{
    char *temp;
    int top, seek, k;
    for (top = 0; top < num-1; top++)
    {
        for (seek = top + 1; seek < num; seek++)
        {
            if ((fetch(strings[top]))>(fetch(strings[seek])))
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    }        
    puts("\nSorted by length of first word:\n");
    for (k = 0; k < num; k++)
        puts(strings[k]);
}

int fetch(char *st)
{
    int i;
    for(i=0; *st!='\0'; i++)
    {
        while(isspace(*(st+i)) && i<1)
        {
            i=-1;
            continue;
        }
        if(isspace(*(st+i)) && i>=1)
            return i-1;
    }
    return 0;
}