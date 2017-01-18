#include<stdio.h>
#include<string.h>
#define LEN 10
int dayssofar(char * mon);
char * s_gets(char * st, int n);
struct month{
    char name[LEN];
    char abr[4];
    int days;
    int num;
};
struct month months[12] =
{
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},   
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};

int main(void)
{
    char st[10];
    printf("Enter a month and I'll tell you how many days are in the year up through that month: ");
    char *choice=s_gets(st, LEN);
    puts(choice);
    printf("There are %d days through the month of %s.\n", dayssofar(choice), choice);
    return 0;
}

int dayssofar(char * mon)
{
    int i=0;
    int j;
    int days=0;
    while(strcmp(mon, months[i].name)!=0)
        i++;
        if(i==12)
            return -1;
    puts(mon);
    puts(months[i].name);
    if(strcmp(mon, months[i].name)==0)
        for(j=0; j<=i; j++)
            days+=months[j].days;
    return days;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}