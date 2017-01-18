#include<stdio.h>

int main(void)
{
    int row, height, space, asc, des;
    char input;
    printf("Enter an uppercase letter and I'll build you a pyramid: ");
    scanf("%c", &input);
    height=input-65;
    //outer loop for rows
    for(row=0; row<=height; row++)
    {
        //inner loop 1 for spaces
        for(space=(height-row); space>0; space--)
            printf(" ");
         //inner loop 2 for ascending letters
        for(asc=0; asc<=row; asc++)
            printf("%c", 65+asc);
        //inner loop 3 for descending letters
        for(des=1; des<=row; des++)
            printf("%c", (65+row-des));
        printf("\n");
    }
    return 0;
}