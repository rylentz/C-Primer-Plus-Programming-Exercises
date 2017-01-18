#include<stdio.h>
#include<string.h>
#define MAX 20
struct info 
{
    int ssn;
    struct {char first[MAX]; char middle[MAX]; char last[MAX];};
};
void show(struct info work[], int num);
int main(void)
{
    struct info cinco[5] =
    {
        {111223333, {"Ingot", "Couth", "Nugget"}},
        {222334444, {"Joe", "Frank", "Mirth"}},
        {333445555, {"Drew", "Sue", "Moo"}},
        {444556666, {"Sally", "", "Drunkard"}},
        {555667777, {"Anne", "Gordon", "Flash"}}
    };
    show(cinco, 5);
    return 0;
}

void show(struct info work[], int num)
{
    int i;
    for(i=0; i<num; i++)
    {
        if(work[i].middle[0])
            work[i].middle[1]='.';
            work[i].middle[2]='\0';
    }
    for(i=0; i<num; i++)
        printf("%s, %s %s -- %d\n", work[i].last, work[i].first, work[i].middle, work[i].ssn);
}