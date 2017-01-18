#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *f1, *f2;
    int line=1, c1, c2, i=0;
    if(argc==3)
    {
        if ((f1 = fopen(argv[1], "r")) == NULL)
        {
            fprintf(stderr, "Can't open %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        if (argv[2] != '\0')
        {   
            if ((f2 = fopen(argv[2], "r")) == NULL)
            {    
                fprintf(stderr, "Can't open %s\n", argv[2]);
                exit(EXIT_FAILURE);
            }    
            else
            {
                while(line!=0)
                {
                    while((line%2==1)&&((c1=getc(f1))!=EOF))
                    {
                        putc(c1, stdout);
                        if(c1 == '\n')
                            line++;
                    }
                    while((line%2==0)&&((c2=getc(f2))!=EOF))
                    {
                        putc(c2, stdout);
                        if(c2 == '\n')
                            line++;
                    }
                    if(c1==EOF && i==0)
                    {
                        printf("\n");
                        i++;
                    }
                    if(c2==EOF && i==0)
                    {
                        printf("\n");
                        i++;
                    }
                    if((c1==EOF)||(c2==EOF))
                        line++;
                    if((c1==EOF)&&(c2==EOF))
                        line=0;
                    continue;
                }
                printf("\n");
            }
            printf("\n");
            fclose(f1);
            fclose(f2);
        }
    }    
    return 0;
}
