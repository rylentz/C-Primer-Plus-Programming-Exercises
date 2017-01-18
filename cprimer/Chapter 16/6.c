#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 10
struct names {
    char first[20];
    char last[20];
};
void showarray(const struct names ar[], int n);
int mycomp(const void * p1, const void * p2);
int main(void)
{
    struct names staff[NUM]={{"Ryan", "Lentz"}, {"Jennifer", "Lentz"}, {"Emily", "Tarantini"}, {"Nino", "Tarantini"}, 
    {"Kelly", "Tarantini"}, {"Justin", "Gauvin"}, {"Daniel", "Sorensen"}, {"Frank", "Grape"}, {"Tim", "Ferriss"}, 
    {"Anthony", "Bourdain"}
    };
    puts("Staff list:");
    showarray(staff, NUM);
    qsort(staff, NUM, sizeof(struct names), mycomp);
    puts("\nAlphabetically sorted staff list:");
    showarray(staff, NUM);
    return 0;
}
void showarray(const struct names ar[], int n)
{
    int index;
    for(index = 0; index < n; index++)
        printf("%2d: %s, %s\n", index+1, ar[index].last, ar[index].first);
}
int mycomp(const void * p1, const void * p2)
{
    const struct names *ps1 = (const struct names *) p1;
    const struct names *ps2 = (const struct names *) p2;
    int res;
    res = strcmp(ps1->last, ps2->last); /* compare last names */
    if (res != 0)
        return res;
    else /* last names identical, so compare first names */
        return strcmp(ps1->first, ps2->first);
}