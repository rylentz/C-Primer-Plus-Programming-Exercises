#include<stdio.h>
#include<stdlib.h> /* for library srand() */
#include<time.h> /* for time() */
#include<ctype.h>
#include "7.h" /* for roll_n_dice() */
/* and for roll_count */
int main(void)
{
    int dice, i;
    int sides, sets;
    srand((unsigned int) time(0)); /* randomize seed */
    printf("Enter the number of sets; enter q to stop: ");
    while(scanf("%d", &sets))
    {
        printf("How many sides and how many dice? ");
        scanf("%d %d", &sides, &dice);
        int roll[sets];
        for(i=0; i<sets; i++)
            roll[i] = roll_n_dice(dice, sides);
        printf("Here are the %d sets of %d %d-sided dice throws:\n", sets, dice, sides);
        for(i=0; i<sets; i++)
            printf("%d ", roll[i]);
        printf("\nEnter the number of sets; enter q to stop: ");
    }
    printf("The rollem() function was called %d times.\n", roll_count); /* use extern variable */
    printf("GOOD FORTUNE TO YOU!\n");
    return 0;
}