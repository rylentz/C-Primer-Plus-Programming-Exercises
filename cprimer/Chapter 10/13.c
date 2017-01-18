#include<stdio.h>

#define ROWS 3
#define COLS 5
void input(double array[][COLS], int i);
double avgset(const double array[], int i);
double avgar(const double array[][COLS], int i);
double large(const double array[][COLS], int i);

int main(void)
{
    int row;
    double array[ROWS][COLS];
    printf("Please enter 15 numbers to fill a 3x5 array: ");
    input(array, ROWS);
    for(row=0; row<ROWS; row++)
        printf("The average of set %d of five numbers is: %g\n", row+1, avgset(array[row], COLS));
    printf("The average of all of the numbers is: %g\n", avgar(array, ROWS));
    printf("The largest number is: %g\n", large(array, COLS));
    return 0;
}

void input(double array[][COLS], int i)
{
    int x, y;
    for(x=0; x<i; x++)
    {
        for(y=0; y<COLS; y++)
        {    
            scanf("%lf", &array[x][y]);
            printf("%g ", array[x][y]);
        }
    printf("\n");
    }
}

double avgset(const double array[], int i)
{
    int x;
    double sum, avg;
    for(x=0, sum=0; x<i; x++)
        sum += array[x];
    avg = sum/COLS;
    return avg;
}

double avgar(const double array[][COLS], int i)
{
    int x, y;
    double sum=0, avg;
    for(x=0; x<i; x++)
    {
        for(y=0; y<COLS; y++)
            sum += array[x][y];
    }
    avg = sum/(i*COLS);
    return avg;
}

double large(const double array[][COLS], int i)
{
    int x, y;
    double big;
    for(x=0; x<i; x++)
    {
        for(y=0; y<COLS; y++)
            if(big<array[x][y])
                big = array[x][y];
    }
    return big;
}