#include<stdio.h>
#define ROWS 3
#define COLS 5
void times2(int source[][COLS], int a);
void printar(int array[][COLS], int a);

int main(void)
{
    int array[ROWS][COLS] =
    {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {7,7,7,7,7}
    };
    printf("The contents of array[ROWS][COLS] are: \n");
    printar(array, ROWS);
    times2(array, ROWS);
    printf("Now the contents of array[ROWS][COLS] are: \n");
    printar(array, ROWS);
    return 0;
}

void times2(int source[][COLS], int a)
{
    int x, y;
    for(x=0; x<a; x++)
        for(y=0; y<COLS; y++)
            source[x][y]=source[x][y]*2;
}

void printar(int array[][COLS], int a)
{
    int row, col;
    for(row=0; row<a; row++)
    {
        for(col=0; col<COLS; col++)
            printf("%d ", array[row][col]);
        printf("\n");
    }    
}