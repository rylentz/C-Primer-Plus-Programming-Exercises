#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256
char * s_gets(char * st, int n);

int main(int argc, char *argv[])
{
    FILE *fp;
    char *st;
    char buf[MAX];
    if(argc!=3)
    {
        printf("Usage: %s string filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    st=argv[1];
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stdout,"Can't open %s file.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while((fgets(buf, MAX, fp))!=NULL)
    {
        if(strstr(buf, st)!=NULL)
            fputs(buf, stdout);
    }    
    fclose(fp);
    printf("Done.\n");
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}