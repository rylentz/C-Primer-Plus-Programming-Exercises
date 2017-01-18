#include<stdio.h>

void copy_arr(double ar1[], double source1[], int i);
void copy_ptr(double ar2[], double source2[], int i);
void copy_ptrs(double *ar3, double *start, double *end);
int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    printf(" source[5] == %g, %g, %g, %g, %g\n", source[0], source[1], source[2], source[3], source[4]);
    printf("target1[5] == %g, %g, %g, %g, %g\n", target1[0], target1[1], target1[2], target1[3], target1[4]);
    printf("target2[5] == %g, %g, %g, %g, %g\n", target2[0], target2[1], target2[2], target2[3], target2[4]);
    printf("target3[5] == %g, %g, %g, %g, %g\n", target3[0], target3[1], target3[2], target3[3], target3[4]);
    return 0;
}

void copy_arr(double ar1[], double source1[], int i)
{
    int x;
    for(x=0; x<i; x++)
        ar1[x]=source1[x];
}

void copy_ptr(double ar2[], double source2[], int i)
{
    int x;
    for(x=0; x<i; x++)
    {
        *(ar2+x)=*source2;
        source2++;
        
    }    
}
void copy_ptrs(double *ar3, double *start, double *end)
{
    int x=0;
    while(start<end)
    {
        *(ar3+x)=*start;
        start++;
        x++;
        
    }    
}