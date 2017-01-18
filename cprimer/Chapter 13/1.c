#include<stdio.h>
#include<stdlib.h> 

int main(void)
{
    int ch;
    char name[40];
    FILE *fp; 
    unsigned long count = 0;
    puts("Enter a file name and I'll tell you how many characters it contains.");
    scanf("%s", name);
    if ((fp = fopen(name, "r")) == NULL)
    {
        printf("Can't open %s\n", name);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch,stdout); 
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", name, count);
    return 0;
}