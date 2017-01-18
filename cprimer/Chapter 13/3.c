#include<stdio.h>
#include<stdlib.h> 
#include<ctype.h>

int main(void)
{
    int ch;
    char src[40], cpy[40];
    FILE *source, *copy; 
    printf("Enter the name of the source file: ");
    scanf("%s", src);
    if ((source = fopen(src, "r")) == NULL)
    {
        printf("Can't open %s\n", src);
        exit(EXIT_FAILURE);
    }
    printf("Enter the name of the destination file: ");
    scanf("%s", cpy);
    copy=fopen(cpy, "w");
    while ((ch = getc(source)) != EOF)
    {
        ch=toupper(ch);
        putc(ch, copy); 
    }
    fclose(source);
    fclose(copy);
    return 0;
}