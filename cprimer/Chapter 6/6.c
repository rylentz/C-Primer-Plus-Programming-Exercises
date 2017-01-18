#include<stdio.h>

int main(void)
{
    int l, u, x, sq, cube;
    printf("Please enter a lower limit and an upper limit, separated by a space: ");
    scanf("%d %d", &l, &u);
    
    printf("Integer Squared Cubed\n");
    for(x=l; x<=u; x++)
    {
        sq=x*x;
        cube=x*x*x;
        printf("%d      %d      %d\n", x, sq, cube);   
    }
    return 0;
}
