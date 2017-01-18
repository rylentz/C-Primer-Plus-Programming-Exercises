#include <stdio.h>
int main(void)
{
    int i = 2147483647;
    unsigned int j = 4294967295;
    float toobig = 3.4E38 * 100.0f;
    float toosmall = 0.1234E-30 / 100000000000000.0;
    
    
    printf("Integer overflow looks like this:\n");
    printf("%d %d %d\n", i, i + 1, i + 2);
    printf("%u %u %u\n", j, j+1, j+2);
    
    printf("Floating-point overflow looks like this:\n");
    printf("%e\n", toobig);
    
    printf("Floating-point underflow looks like this:\n");
    printf("%e\n", toosmall);
    
    return 0;
}