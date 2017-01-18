#include<stdio.h>
#include<time.h>
void delay(double t);
int main(void)
{
    double x;
    printf("Enter the number of seconds that you want to wait before the program ends(q to quit): ");
    while(scanf("%lf", &x)==1)
    {
        delay(x);
        printf("Enter another number of seconds or q to quit: ");
    }
    return 0;
}
void delay(double seconds)
{
    clock_t start = clock();
    printf("Start time: %ld\n", start);
    clock_t current = clock();
    double elapsed=((double)current-(double)start)/((double)CLOCKS_PER_SEC);
    while(elapsed < seconds)
    {
        printf(". ");
        current = clock();
    }
    printf("End time: %ld\nTime elapsed: %ld\n", current, current - start);
}