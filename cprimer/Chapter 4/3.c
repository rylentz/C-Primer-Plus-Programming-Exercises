#include <stdio.h>
#include <string.h>

int main(void)
{
    float f = 0.0;
    printf("Enter a floating-point number: \n");
    scanf("%f", &f);
    printf("a. The input is %.1f or %.1e.\n", f, f);
    printf("b. The input is %+.3f or %.3E.\n", f, f);
    return 0;
}
