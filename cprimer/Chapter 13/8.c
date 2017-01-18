//reports the number of times a given character appears in a given file
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 40
int main(int argc, char *argv[])
{
    FILE *fp;
    char name[SIZE];
    int i, ch, count=0;
    if(argc<2)
    {
        printf("Usage: %s character filename\n", argv[0]);   
        exit(EXIT_FAILURE);
    }
    else if(argc==2)
    {
        printf("Enter a file name (enter q to quit): ");
        scanf("%s", name);
        while(strncmp(name,"q", 1))
        {
            if((fp=fopen(name, "r"))==NULL)
            {
                fprintf(stderr, "I couldn't open the file \"%s\"\n", name);
                exit(EXIT_FAILURE);
            }
            while((ch=getc(fp))!=EOF)
                if(ch==*argv[1])
                    count++;
            fclose(fp);
            printf("The character %c occurred in file %s %d times.\n", *argv[1], name, count);
            printf("Enter a file name (enter q to quit): ");
            scanf("%s", name);
        }
    }
    else
    {
        for(i=2; i<argc; i++)
        {
            if((fp=fopen(argv[i], "r"))==NULL)
            {
                fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[i]);
                exit(EXIT_FAILURE);
            }
            while((ch=getc(fp))!=EOF)
                if(ch==*argv[1])
                    count++;
            fclose(fp);
            printf("The character %c occurred in file %s %d times.\n", *argv[1], argv[i], count);
        }
    }
    return 0;
}
