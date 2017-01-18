#include<stdio.h>
#define ROWS 3
#define COLS 5
void copy_arr(int a, int b, double source[a][b], double copy[a][b]);
void printar(int a, int b, double array[a][b]);

int main(void)
{
    double copy[ROWS][COLS] = {{0}};
    double array[ROWS][COLS] =
    {
        {1.1,1.2,1.3,1.4,1.5},
        {5.1,4.1,3.1,2.1,1.1},
        {7,7,7,7,7}
    };
    printf("The contents of array[ROWS][COLS] are: \n");
    printar(ROWS, COLS, array);
    printf("The contents of copy[ROWS][COLS] are: \n");
    printar(ROWS, COLS, copy);
    copy_arr(ROWS, COLS, array, copy);
    printf("Now the contents of copy[ROWS][COLS] are: \n");
    printar(ROWS, COLS, copy);
    return 0;
}

void copy_arr(int a, int b, double source[a][b], double copy[a][b])
{
    int x, y;
    for(x=0; x<a; x++)
        for(y=0; y<b; y++)
            copy[x][y]=source[x][y];
}

void printar(int a, int b, double array[a][b])
{
    int row, col;
    for(row=0; row<a; row++)
    {
        for(col=0; col<b; col++)
            printf("%g ", array[row][col]);
        printf("\n");
    }    
}