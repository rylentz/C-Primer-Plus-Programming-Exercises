#include<stdio.h>

void menu(void);
int choice(int low, int high);

int main(void)
{
    int ans;
    menu();
    while((ans = choice(1, 4)) != 4)
    {
        printf("You chose %d.\n", ans);
        menu();
    }
    printf("Buh-bye now.\n");
    return 0;
}

void menu(void)
{
    printf("Please choose one of the following:\n");
    printf("1) copy files               2) move files\n");
    printf("3) remove files             4) quit\n");
}

int choice(int low, int high)
{
    int input, good;
    good = scanf("%d", &input);
    while(good == 1 && (input < low || input > high))
    {
        printf("Please enter a valid choice: ");
        menu();
        scanf("%d", &input);
    }
    if(good != 1)
    {
        printf("Non-numeric input.");
        input=4;
    }
    return input;
}
