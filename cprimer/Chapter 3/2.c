#include <stdio.h>
int main(void)
{
    int ch;
    
    printf("Please enter a number between 33 and 126: ");
    scanf("%d", &ch);
    printf("The ASCII character for %d is %c.\n", ch, ch);
    return 0;
}