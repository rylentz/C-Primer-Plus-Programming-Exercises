#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10
#define NUM 100
void stsrt(int *strings, int num);
int main(void)
{
    int randos[NUM];
    int *pt;
    int count, i;
    pt = randos;
    srand((unsigned int) time(0));
    for(count = 0; count < NUM; count++)
        randos[count] = rand()%MAX+1;
    stsrt(pt, NUM);
    for(i=0; i<NUM; i++)
        printf("%d ", randos[i]);
    printf("\nDone.\n");
    return 0;
}

void stsrt(int *strings, int num)
{
    int top, seek, temp;
    for (top = num-1; top >= 0; top--)
        for (seek = top - 1; seek >= 0; seek--)
            if (strings[top]<strings[seek])
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}