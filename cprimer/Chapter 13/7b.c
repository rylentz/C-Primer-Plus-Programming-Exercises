#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *f1, *f2;
    int line=1, c1, c2;
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
                    while(line%2==1)
                    {
                        while(((c1=getc(f1))!='\n')&&(c1!=EOF))
                            putc(c1, stdout);
                        line++;
                    }
                    while(line%2==0)
                    {
                        while(((c2=getc(f2))!='\n')&&(c2!=EOF))
                            putc(c2, stdout);
                        line++;
                    }
                    printf("\n");
                    
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
