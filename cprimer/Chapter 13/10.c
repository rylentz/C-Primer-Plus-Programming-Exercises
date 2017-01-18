#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 40
int main(void)
{
    FILE * fp;
    char name[SIZE];
    char ch;
    int i, x=0;
    printf("Enter the file to be read: ");
    scanf("%s", name);
    if ((fp = fopen(name, "r")) == NULL)
    {
        fprintf(stdout,"Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter a file location for printing, or q to quit: ");
    
    while((scanf("%d", &i))==1)
    {
        if(i<0)
            break;
        while((ch=getc(fp))!=EOF)
        {
            if(x>=i)
            {    
                putchar(ch);
                if(ch=='\n')
                    break;
            }    
            x++;
        }
        rewind(fp);
        x=0;
        printf("\nEnter another file location for printing, or q to quit: ");
    }
    fclose(fp);
    puts("Done.");
    return 0;
}