#include <stdio.h>
#include <stdlib.h> // for exit()
#include <string.h>
#define SIZE 40

int main(void)
{
    FILE *in, *out; // declare two FILE pointers
    int ch;
    char st[SIZE];
    char name[SIZE];
    int count = 1;
    printf("Enter the name of the file to be modified: ");
    scanf("%s", st);
    if ((in = fopen(st, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", st);
        exit(EXIT_FAILURE);
    }
    strncpy(name, st, SIZE); // copy filename
    name[strlen(st)+1] = '\0';
    strcat(name, ".red"); // append .red
    if ((out = fopen(name, "w")) == NULL)
    {
        printf("Can't create output file.\n"); 
        exit(3);
    }
    for(count=1; (ch = getc(in)) != EOF; count++)
        if(count % 3 == 0)
            putc(ch, out); // print every 3rd char
    if(fclose(in) != 0 || fclose(out) != 0)
        printf("Error in closing files\n");
    puts("Done.");
    return 0;
}
