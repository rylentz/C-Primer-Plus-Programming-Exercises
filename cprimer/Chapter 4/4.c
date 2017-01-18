#include <stdio.h>
#include <string.h>

int main(void)
{
    float height;
    char name[20];
    printf("Enter your name and your heigh in inches: \n");
    scanf("%s %f", name, &height);
    printf("%s, you are %.3f feet tall.\n", name, height / 12);
    return 0;
}
