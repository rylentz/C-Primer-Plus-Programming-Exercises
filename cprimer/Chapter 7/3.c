#include<stdio.h>

int main(void)
{
    int num, even=0, odd=0;
    float esum=0.0, osum=0.0;
    printf("Enter a series of integers separated by spaces. Finish with 0 followed by ENTER: ");
    while((scanf("%d", &num))==1)
    {
        if(num==0)
            break;
        else if(num%2==0)
        {
            even++;
            esum+=num;
        }
        else
        {
            odd++;
            osum+=num;
        }
    }
    printf("Evens=%d  Avg Even=%.1f  Odds=%d  Avg Odd=%.1f\n", even, esum/even, odd, osum/odd);
    return 0;
}