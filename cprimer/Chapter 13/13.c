#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 40

int main(void)
{
    FILE *fr, *fw;
    char name[SIZE];
    int ch, i, j, rows=20, cols=30;
    int temp[rows][cols];
    char img[rows][cols+1];
    printf("Enter the name of a text file and I will use it to create an image: ");
    scanf("%s", name);
    if ((fr = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", name);
        exit(EXIT_FAILURE);
    }
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
            while(isdigit(ch=getc(fr)))
                temp[i][j]=ch;
    fclose(fr);
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++) 
            printf("%c", temp[i][j]);
        printf("\n");
    }
    printf("\n");
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)        
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
    fputs(*img, stdout);
    if ((fw = fopen("image", "w+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", "image");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<rows; i++)
        for(j=0; j<cols+1; j++)
        {
            ch=img[i][j];
            putc(ch, fw);
        }
    fputs(*img, fw);
    fclose(fw);
    puts("Done.");
    return 0;
}