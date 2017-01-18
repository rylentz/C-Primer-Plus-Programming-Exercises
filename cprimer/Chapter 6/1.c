#include<stdio.h>

int main(void)
{
    char lower[26];
    int c;
    for(c=0; c<26; c++)
    {
        lower[c] = c + 97;
        printf("%c ", lower[c]);
    }
    printf("\n");
    return 0;
}