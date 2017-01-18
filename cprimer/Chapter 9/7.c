#include<stdio.h>
#include<ctype.h>

int makenum(char z);

int main(void)
{
    char ch;
    printf("Type whatever you like. It could even be an entire book. Press [ctrl+d] to indicate you are finished.\n");
    printf("Each letter you input will be converted to it's numerical location in the alphabet.\n");
    printf("A -1 will replace all other characters.\n");
    while((ch=getchar())!= EOF)
        printf("%d ", makenum(ch));
    printf("\n");
    return 0;
}

int makenum(char z)
{
    if(isalpha(z)!=0)
    {
        if(islower(z)!=0)
            z-=96;
        else
            z-=64;
        return z;
    }
    else
        return -1;
}