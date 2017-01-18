#include<stdio.h>
#include<stdlib.h>
#define BUFLEN 256

int main(int argc,char *argv[])
{
    char buf[BUFLEN];
    FILE *source, *copy;
    if(argc!=3)
    {
        printf("Usage: %s character filename\n", argv[0]);   
        exit(EXIT_FAILURE);
    }
    if((source=fopen(argv[1], "r"))==NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    copy=fopen(argv[2], "w");
    while((fgets(buf, BUFLEN, source))!=NULL)
        fputs(buf, copy);
    fclose(source);
    fclose(copy);
    return 0;
}