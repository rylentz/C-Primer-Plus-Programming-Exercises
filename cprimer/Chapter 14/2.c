#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"months.h"
#define LEN 10
int dayssofar(int day, int month, int year);
int convert(char *input);
int main(void)
{
    char moname[10];
    int day, year;
    puts("Enter a month(name, abbreviation or number), a day(number) and a year(number).");
    puts("I'll tell you how many days are in the year up through that day.");
    scanf("%s %d %d", moname, &day, &year);
    int mono=convert(moname);
    printf("For the year %d, there are %d days through the %d day of %s.\n", year, dayssofar(day, mono, year), day, months[mono].name);
    return 0;
}

int dayssofar(int day, int month, int year)
{
    int j;
    int total=0;
    for(j=0; j<month; j++)
        total+=months[j].days;
    total+=day;
    if(year%4==0 && month>2)
        total+=1;
    return total;
}

int convert(char *input)
{
    int i=0;
    if(isdigit(input[0]))
    {
        i=((int)input)-1;
        if(i<0 || i>11)
        {
            printf("Invalid input.");
            exit(EXIT_FAILURE);
        }
        else
            return i;
    }
    else
    {
        while(input[i])
        {
            input[i]=tolower(input[i]);
            i++;
        }
        i=0;
        while(strncmp(input, months[i].abr, 3)!=0)
        {
            i++;
            if(i==12)
            {
                printf("Invalid input.");
                exit(EXIT_FAILURE);
            }
        }
    }
    return i;
}
