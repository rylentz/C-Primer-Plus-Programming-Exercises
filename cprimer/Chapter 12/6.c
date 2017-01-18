#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define NUM 1000
void tally(int *arr, int num);
int main(void)
{
    int randos[NUM];
    int *pt;
    int count, i;
    unsigned int seed;
    pt = randos;
    printf("To test a random number generator, you will be asked for a total of %d seed values, one at a time.\n", MAX);
    for(i=0; i<MAX; i++)
    {
        printf("Enter a seed value (%d to go): ", MAX-i);
        if(scanf("%d", &seed)==1)
        {
            srand(seed);
            for(count = 0; count < NUM; count++)
                randos[count] = rand()%MAX+1;
            tally(pt, NUM);
        }
        
    }
    
    printf("All done.\n");
    return 0;
}

void tally(int *arr, int num)
{
    int i;
    int one=0, two=0, three=0, four=0, five=0, six=0, seven=0, eight=0, nine=0, ten=0;
    for(i=0; i<num; i++)
    {
        if(arr[i]==1)
            one++;
        else if(arr[i]==2)
            two++;
        else if(arr[i]==3)
            three++;
        else if(arr[i]==4)
            four++;
        else if(arr[i]==5)
            five++;
        else if(arr[i]==6)
            six++;
        else if(arr[i]==7)
            seven++;
        else if(arr[i]==8)
            eight++;
        else if(arr[i]==9)
            nine++;
        else if(arr[i]==10)
            ten++;
    }
    printf(" 1 occurred %d times.\n", one);
    printf(" 2 occurred %d times.\n", two);
    printf(" 3 occurred %d times.\n", three);
    printf(" 4 occurred %d times.\n", four);
    printf(" 5 occurred %d times.\n", five);
    printf(" 6 occurred %d times.\n", six);
    printf(" 7 occurred %d times.\n", seven);
    printf(" 8 occurred %d times.\n", eight);
    printf(" 9 occurred %d times.\n", nine);
    printf("10 occurred %d times.\n", ten);
}

