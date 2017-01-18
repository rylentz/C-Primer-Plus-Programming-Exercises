#include<stdio.h>
#include<string.h>
#define MAX 20
struct info 
{
    int ssn;
    struct {char first[MAX]; char middle[MAX]; char last[MAX];};
};
void show(struct info work);
int main(void)
{
    int i;
    struct info cinco[5] =
    {
        {111223333, {"Ingot", "Couth", "Nugget"}},
        {222334444, {"Joe", "Frank", "Mirth"}},
        {333445555, {"Drew", "Sue", "Moo"}},
        {444556666, {"Sally", "", "Drunkard"}},
        {555667777, {"Anne", "Gordon", "Flash"}}
    };
    for(i=0; i<5; i++)
        show(cinco[i]);
    return 0;
}

void show(struct info work)
{
    if(work.middle[0])
        work.middle[1]='.';
        work.middle[2]='\0';
    printf("%s, %s %s -- %d\n", work.last, work.first, work.middle, work.ssn);
}