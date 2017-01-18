#include<stdio.h>
#define ROWS 2
#define COLS 5
void copy_arr(double copy[], const double source[], int i);

int main(void)
{
    int row, col;
    double copy[ROWS][COLS] = {{0}};
    double array[ROWS][COLS] =
    {
        {1.1,1.2,1.3,1.4,1.5},
        {5.1,4.1,3.1,2.1,1.1}
    };
    printf("The contents of array[ROWS][COLS] are: \n");
    for(row=0; row<ROWS; row++)
    {
        for(col=0; col<COLS; col++)
            printf("%g ", array[row][col]);
        printf("\n");
    }    
    printf("The contents of copy[ROWS][COLS] are: \n");
    for(row=0; row<ROWS; row++)
    {
        for(col=0; col<COLS; col++)
            printf("%g ", copy[row][col]);
        printf("\n");
    } 
    
    printf("Now the contents of copy[ROWS][COLS] are: \n");
    for(row=0; row<ROWS; row++)
    {
        for(col=0; col<COLS; col++)
        {
            copy_arr(copy[row], array[row], COLS);
            printf("%g ", copy[row][col]);
        }
        printf("\n");
    }
    return 0;
}

void copy_arr(double copy[], const double source[], int i)
{
    int x;
    for(x=0; x<i; x++)
        copy[x]=source[x];
}