#include <stdio.h>
#include<math.h>
int main(void)
{
    int limit, count;
    double s_one, s_two;
    printf("Enter the number of terms you want: ");
    while(scanf("%d", &limit)>0)
    {
        printf("Infinite Series 1           Infinite Series 2\n");
        for (s_one=0, s_two=0, count=1; count<=limit; count++)
        {
            s_one += 1.0/count;
            s_two += 1.0/count*(-pow(-1, count));
            printf("%.5lf                       %.5lf\n", s_one, s_two);
        }
        printf("Enter the number of terms you want: ");
    }
    return 0;
}