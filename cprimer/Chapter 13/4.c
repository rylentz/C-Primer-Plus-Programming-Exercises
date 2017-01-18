#include<stdio.h>
#include<stdlib.h>
#define LEN 256

int main(int argc,char *argv[])
{
    FILE *fp;
    if(argc>1)
    {
        int i;
        char buf[LEN];
        for(i=1; i<argc; i++)
        {
            if((fp = fopen(argv[i], "r"))==NULL)
            {
                fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[1]);
                exit(EXIT_FAILURE);
            }
            while((fgets(buf, LEN, fp))!=NULL)
                fputs(buf, stdout);
            fclose(fp);
        }
    }
    return 0;
}