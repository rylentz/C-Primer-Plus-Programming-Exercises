#include<stdio.h>
#include<ctype.h>

int main(void)
{
    int ch, upper=0, lower=0, other=0;
    
    printf("Type whatever you like, and I will let you know how many uppercase, lowercase and other characters you used.\n");
    printf("Enter [ctrl]+[d] to quit.\n");
    while((ch=getchar()) != EOF)
    {    
        if(islower(ch)!=0)
            lower++;
        else if(isupper(ch)!=0)
            upper++;
        else if(isspace(ch)==0)
            other++;
    }    
    printf("\nUppercase: %d   Lowercase: %d   Other: %d\n", upper, lower, other);
    return 0;
}