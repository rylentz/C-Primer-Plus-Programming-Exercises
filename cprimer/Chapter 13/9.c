#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41
int main(void)
{
    FILE *fp;
    char words[MAX];
    int i=1, ch;
    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout,"Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp))!=EOF)
        if(ch=='\n')
            i++;
    puts("Enter words to add to the file; press the # key at the beginning of a line to terminate.");
    while ((fscanf(stdin,"%s", words) == 1) && (words[0] != '#'))
    {    
        fprintf(fp, "%d. %s\n", i, words);
        i++;
    }    
    puts("File contents:");
    rewind(fp); /* go back to beginning of file */
    while ((ch=getc(fp))!=EOF)
        putchar(ch);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr,"Error closing file\n");
    return 0;
}