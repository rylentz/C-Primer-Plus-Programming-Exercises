#include<stdio.h>

int main(int argc, char *argv[])
{
    for(int i=1; i<argc; i++)
        printf("%s ", argv[argc-i]);
        puts("\n");
    return 0;
}