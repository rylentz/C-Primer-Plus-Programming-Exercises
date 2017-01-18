#include <stdio.h>

int main(void)
{
    int n, m;
    printf("Feel free to enter a number:\n");
    scanf("%d", &n);
    m = n + 9;
    
    while(n++ < m)
    {
        printf("%d\n", n);
    }
    printf("Done!\n");
    return 0;
}