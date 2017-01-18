#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define ROWS 20
#define COLS 30
#define SIZE 40

int main(void)
{
    FILE *fr, *fw;
    char name[SIZE];
    int ch, i, j;
    int temp[ROWS][COLS];
    char img[ROWS][COLS+1];
    printf("Enter the name of a text file and I will use it to create an image: ");
    scanf("%s", name);
    if ((fr = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", name);
        exit(EXIT_FAILURE);
    }
    for(i=0; i<ROWS; i++)
        for(j=0; j<COLS; j++)
            while(isdigit(ch=getc(fr)))
                temp[i][j]=ch;
    fclose(fr);
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++) 
            printf("%c", temp[i][j]);
        printf("\n");
    }
    printf("\n");
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)        
        {
            if(temp[i][j]=='0')
                img[i][j]=' ';
            if(temp[i][j]=='1')
                img[i][j]='.';
            if(temp[i][j]=='2')
                img[i][j]='-';
            if(temp[i][j]=='3')   
                img[i][j]='^';
            if(temp[i][j]=='4')
                img[i][j]='|';
            if(temp[i][j]=='5')
                img[i][j]='+';
            if(temp[i][j]=='6')
                img[i][j]='*';
            if(temp[i][j]=='7')
                img[i][j]='#';
            if(temp[i][j]=='8')
                img[i][j]='&';
            if(temp[i][j]=='9')
                img[i][j]='$';
        }
        img[i][30]='\n';
    }
    if ((fw = fopen("image", "w+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", "image");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<ROWS; i++)
        for(j=0; j<COLS+1; j++)
        {
            ch=img[i][j];
            putc(ch, fw);
        }
    rewind(fw);
    while((ch=getc(fw))!=EOF)
        putc(ch, stdout);
    fclose(fw);
    puts("Done.");
    return 0;
}