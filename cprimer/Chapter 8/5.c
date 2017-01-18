#include <stdio.h>
int main(void)
{
    int opt, guess=50, max=100, min=1;
    printf("Pick an integer from 1 to 100. I will try to guess it.\n");
    printf("Respond with 'c' for correct, 'l' for low or 'h' for high.\n");
    printf("Is your number %d?\n", guess);
    while((opt=getchar())!=0)
    {
        switch(opt)
        {
            case 'c' :  printf("I knew I could do it!\n");
                        return 0;
            case 'l' :  min=guess+1;
                        guess=(max+min)/2;
                        printf("Oops! Let me try again. Is it %d?\n", guess);
                        opt=getchar();
                        break;
            case 'h' :  max=guess-1;
                        guess=(max+min)/2;
                        printf("Oops! Let me try again. Is it %d?\n", guess);
                        opt=getchar();
                        break;
            default  :  printf("Invalid input. Please respond with 'c' for correct, 'l' for low or 'h' for high.\n");
                        break;
        }
    }
    return 0;
}