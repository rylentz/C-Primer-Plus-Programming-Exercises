#include <stdio.h>
#include<math.h>
#define SIZE 8
int main(void)
{
    int x, y, eight[SIZE];
    for (x = 0, y=1; x < SIZE; x++, y++)
    {
        eight[x] = pow(2,y);
        printf("%d ", eight[x]);
    }
    printf("\n");
    return 0;  
}