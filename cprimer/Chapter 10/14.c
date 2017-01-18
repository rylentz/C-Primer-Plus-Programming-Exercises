#include<stdio.h>

#define ROWS 3
#define COLS 5
void input(int i, int p, double array[i][p]);
double avgset(int i, int p, double array[i][p]);
double avgar(int i, int p, double array[i][p]);
double large(int i, int p, double array[i][p]);

int main(void)
{
    int row;
    double array[ROWS][COLS];
    printf("Please enter 15 numbers to fill a 3x5 array: ");
    input(ROWS, COLS, array);
    for(row=0; row<ROWS; row++)
        printf("The average of set %d of five numbers is: %g\n", row+1, avgset(row, COLS, array));
    printf("The average of all of the numbers is: %g\n", avgar(ROWS, COLS, array));
    printf("The largest number is: %g\n", large(ROWS, COLS, array));
    return 0;
}

void input(int i, int p, double array[i][p]){
    int x, y;
    for(x=0; x<i; x++)
    {
        for(y=0; y<p; y++)
        {    
            scanf("%lf", &array[x][y]);
            printf("%g ", array[x][y]);
        }
    printf("\n");
    }
}

double avgset(int i, int p, double array[i][p])
{
    int x;
    double sum, avg;
    for(x=0, sum=0; x<p; x++)
        sum += array[i][x];
    avg = sum/COLS;
    return avg;
}

double avgar(int i, int p, double array[i][p])
{
    int x, y;
    double sum=0, avg;
    for(x=0; x<i; x++)
    {
        for(y=0; y<p; y++)
            sum += array[x][y];
    }
    avg = sum/(i*p);
    return avg;
}

double large(int i, int p, double array[i][p])
{
    int x, y;
    double big;
    for(x=0; x<i; x++)
    {
        for(y=0; y<p; y++)
            if(big<array[x][y])
                big = array[x][y];
    }
    return big;
}