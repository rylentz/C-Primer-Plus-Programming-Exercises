#include<stdio.h>

void calc();
int L, U, LL, UU, LS, SUM;
    
int main(void)
{
    printf("Enter lower and upper integer limits: ");
    scanf("%d %d", &L, &U);
    while(L<U)
    {
        LL=L*L;
        UU=U*U;
        calc();
        printf("The sums of the squares from %d to %d is %d\n", LL, UU, SUM);
        printf("Enter the next set of limits: ");
        scanf("%d %d", &L, &U);
    }
    printf("Done\n");
    return 0;    
}
void calc()
{
    for(SUM=0; L<=U; L++)
    {
        LS=L*L;
        SUM=SUM+LS;
    }
}