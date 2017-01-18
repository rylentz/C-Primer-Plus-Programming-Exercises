#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define NUM 100
#define PICKS 20
void lottery(const int ar[], int size, int picks);

int main(void)
{
    int ar[NUM];
    int i;
    for(i=0; i<NUM; i++)
        ar[i] = i;
    printf("\n");
    lottery(ar, NUM, PICKS);
    puts("Hope you won!");
    return 0;
}
void lottery(const int ar[], int size, int picks)
{
    int i, random;
    char randoms[picks];
    srand((unsigned int) time(0));
    printf("Pick  Number\n");
    for(i=0; i<picks; i++)
    {
        random = rand()%size;
        while(strchr(randoms, (char)random)!=NULL)
            random = rand()%size;
        randoms[i] = (char)random;
        printf("%2d:    %2d\n", i+1, ar[random]);
    }
}