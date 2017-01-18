#include<stdio.h>
#include<ctype.h>

int main(void)
{
    int ch;
    double letters=0, words=0;
    
    printf("Type whatever you like, and I will let you know the average number of letters per word.\n");
    printf("Enter [ctrl]+[d] to quit.\n");
    while((ch=getchar()) != EOF)
    {    
        if(isalpha(ch)!=0)
            letters++;
        else if(isspace(ch)!=0)
            words++;
    }    
    printf("\nWords: %.0f   Letters: %.0f   Average Letters per Word: %.2f\n", words, letters, (letters/words));
    return 0;
}