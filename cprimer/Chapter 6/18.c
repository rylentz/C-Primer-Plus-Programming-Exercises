#include<stdio.h>

int main(void)
{
    const int Dunbar=150;
    int n=5, w=0;
    printf("Week        Friends\n");
    printf(" 0             5\n");
    do
    {
        w++;
        n=n-w;
        n=n*2;
        printf(" %d             %d\n", w, n);
    } while(n<=Dunbar);
    
    return 0;
}