#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 40
void debug(int rows, int cols, int ar[rows][cols]);

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
    debug(rows, cols, temp);
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
    fputs(*img, fw);
    fclose(fw);
    puts("Done.");
    return 0;
}

void debug(int rows, int cols, int ar[rows][cols])
{
    int i, j;
    for(i=1; i<rows-1; i++)
        for(j=1;j<cols-1; j++)
        {
            if((unsigned int)(ar[i][j]-ar[i-1][j])>1 && (unsigned int)(ar[i][j]-ar[i+1][j])>1 && (unsigned int)(ar[i][j]-ar[i][j+1])>1 && (unsigned int)(ar[i][j]-ar[i][j-1])>1)
                ar[i][j]=(int)(ar[i-1][j]+ar[i+1][j]+ar[i][j+1]+ar[i][j-1])/4;
        }
    for(i=0, j=1; j<cols-1; j++)
    {
        if((unsigned int)(ar[i][j]-ar[i+1][j])>1 && (unsigned int)(ar[i][j]-ar[i][j+1])>1 && (unsigned int)(ar[i][j]-ar[i][j-1])>1)
                ar[i][j]=(int)(ar[i+1][j]+ar[i][j+1]+ar[i][j-1])/3;
    }
    for(i=19, j=1; j<cols-1; j++)
    {
        if((unsigned int)(ar[i][j]-ar[i-1][j])>1 && (unsigned int)(ar[i][j]-ar[i][j+1])>1 && (unsigned int)(ar[i][j]-ar[i][j-1])>1)
                ar[i][j]=(int)(ar[i-1][j]+ar[i][j+1]+ar[i][j-1])/3;
    }
    for(j=29, i=1; i<rows-1; i++)
    {
        if((unsigned int)(ar[i][j]-ar[i-1][j])>1 && (unsigned int)(ar[i][j]-ar[i+1][j])>1 && (unsigned int)(ar[i][j]-ar[i][j-1])>1)
                ar[i][j]=(int)(ar[i-1][j]+ar[i+1][j]+ar[i][j-1])/3;
    }
    for(j=0, i=1; i<rows-1; i++)
    {
        if((unsigned int)(ar[i][j]-ar[i-1][j])>1 && (unsigned int)(ar[i][j]-ar[i+1][j])>1 && (unsigned int)(ar[i][j]-ar[i][j+1])>1)
                ar[i][j]=(int)(ar[i-1][j]+ar[i+1][j]+ar[i][j+1])/3;
    }
    if((unsigned int)(ar[0][0]-ar[1][0])>1 && (unsigned int)(ar[0][0]-ar[0][1])>1)
        ar[0][0]=(int)(ar[1][0]+ar[0][1])/2;
    if((unsigned int)(ar[0][29]-ar[1][29])>1 && (unsigned int)(ar[0][29]-ar[0][28])>1)
        ar[0][29]=(int)(ar[1][29]+ar[0][28])/2;
    if((unsigned int)(ar[19][0]-ar[18][0])>1 && (unsigned int)(ar[19][0]-ar[19][1])>1)
        ar[19][0]=(int)(ar[18][0]+ar[19][1])/2;
    if((unsigned int)(ar[19][29]-ar[18][29])>1 && (unsigned int)(ar[19][0]-ar[19][28])>1)
        ar[19][29]=(int)(ar[18][0]+ar[19][28])/2;
}        