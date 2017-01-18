#include <stdio.h>
int main(void)
{
    int x, eight[8];
    printf("Enter eight numbers separated by spaces: ");
    for (x = 0; x < 8; x++)
        scanf("%d", &eight[x]);
    for(x=7; x>=0; x--)
        printf("%d ", eight[x]);
    printf("\n");
    return 0;  
}