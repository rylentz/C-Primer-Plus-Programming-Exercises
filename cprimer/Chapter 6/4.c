#include<stdio.h>

int main(void)
{
    int row, col, let=65;
    for(row=0; row<6; row++)
    {
        for(col=0; col<=row; col++)
            printf("%c", col+let);
        printf("\n");
        let+=col;
    }
    return 0;
}