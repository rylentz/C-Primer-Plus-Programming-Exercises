#include <stdio.h>
#include <string.h>

int main(void)
{
    float Mbs, MB;
    printf("Enter your download speed in Mbs and your file size in MB: \n");
    scanf("%f %f", &Mbs, &MB);
    float time = (MB * 8)/ Mbs;
    printf("At %.2f megabits per second, a file of %.2f megabytes \ndownloads in %.2f seconds.\n", Mbs, MB, time);
    return 0;
}
