#include<stdio.h>
#include<ctype.h>
int myatoi(char *s);
int main(int argc, char *argv[])
{
    int x = myatoi(argv[argc-1]);
    printf("%d\n", x);
    return 0;
}

int myatoi(char *s)
{
    int i=0, sign=1, ret=0;
    if(s[0]=='-')
        {
            sign=-1;
            i++;
        }
    for(; s[i]!='\0'; i++)
    {
        if(!isdigit(s[i]))
            return 0;
        else
            ret=ret*10+s[i]-'0';
    }
    return sign*ret;
}