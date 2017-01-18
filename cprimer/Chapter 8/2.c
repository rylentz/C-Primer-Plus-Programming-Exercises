#include<stdio.h>

int main(void)
{
    int ch, ten;
    
    printf("Type whatever you like, and I will let you know the ASCII decimal value of each and every character!\n");
    printf("Enter [ctrl]+[d] to quit.\n");
    for(ten=0; (ch=getchar()) != EOF; ten++)
    {    
        while(ten==10)
        {
            printf("\n");
            ten=0;
        }
        if((ch<9 || ch>10) && ch<32)
            printf("\'^%c\'=%d ", (ch+64), ch);
        else if(ch==9)
            printf("\'\\t\'=%d ", ch);
        else if(ch==10)
        {
            printf("\'\\n\'=%d\n", ch);
            ten=-1;
        }
        else
            printf("\'%c\'=%d ", ch, ch);
    }    
    printf("\n");
    return 0;
}