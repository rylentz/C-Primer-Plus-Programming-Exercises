#include<stdio.h>

int main(void)
{
    int row, col;
    for(row=0; row<6; row++)
    {
        for(col=0; col<=row; col++)
            printf("%c", 70-col);
        printf("\n");
    }
    return 0;
}