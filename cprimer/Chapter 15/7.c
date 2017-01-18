#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define F_MASK 0xFF000000
#define S_MASK 0xFF0000
//alignment options
#define LEFT 0x10
#define CENTER 0x20 
#define RIGHT 0x40
#define A_MASK 0x70
//font options
#define BOLD 1
#define ITALIC 2
#define UNDER 4

void show(const unsigned int p);
void eatline(void);
unsigned int type(unsigned int p);
unsigned int size(unsigned int p);
unsigned int alignment(unsigned int p);

int main(void)
{
    unsigned int f=0x1010010; // 0000 0001 0000 0001 0000 0000 0000 0000
    char opt;
    show(f);
    puts("Which font parameter would you like to modify?");
    puts("f)font   s)size   a)alignment   b)toggle bold   i)toggle italics   u)toggle underline   q)quit");
    while((opt=tolower(getchar()))!='q')
    {
        eatline();
        while(strchr("fsabiuq", opt)==NULL)
        {
            printf("Please enter a f, s, a, b, i, u or q: ");
            opt=tolower(getchar());
            eatline();
        }
        switch(opt)
        {
            case 'f'    : f=type(f); break;
            case 's'    : f=size(f); break;
            case 'a'    : f=alignment(f); break;
            case 'b'    : f^=BOLD; break;
            case 'i'    : f^=ITALIC; break;
            case 'u'    : f^=UNDER; break;
            case 'q'    : puts("Buh-bye."); return 0;
        }
        show(f);
        puts("Which font parameter would you like to modify?");
        puts("f)font   s)size   a)alignment   b)toggle bold   i)toggle italics   u)toggle underline   q)quit");
    }
    puts("Buh-bye.");
    return 0;
}

void show(const unsigned int p)
{
    printf(" ID SIZE ALIGNMENT   B   I   U\n");
    printf("%3d %3d", (p>>24), (p&~F_MASK)>>16);
    switch(p&A_MASK)
    {
        case LEFT   : printf("     left"); break;
        case CENTER : printf("   center"); break;
        case RIGHT  : printf("    right"); break;
    }
    printf("    %s", (p&BOLD)==BOLD? " on":"off");
    printf(" %s", (p&ITALIC)==ITALIC? " on":"off");
    printf(" %s\n", (p&UNDER)==UNDER? " on":"off");
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
unsigned int type(unsigned int p)
{
    unsigned int num;
    printf("Enter the new font ID(0-255): ");
    while((scanf("%d", &num))==1)
    {
        eatline();
        if(num>255)
            printf("Please enter a number from 0 to 255: ");
        else
        {
            num<<=24;
            p&=~F_MASK;
            p|=num;
            return p;
        }
    }
    puts("Invalid input. Better luck next time.");
    return 0;
}
unsigned int size(unsigned int p)
{
    unsigned int num;
    printf("Enter the new font size(0-127): ");
    while((scanf("%d", &num))==1)
    {
        eatline();
        if(num>127)
            printf("Please enter a number from 0 to 127: ");
        else
        {
            num<<=16;
            p&=~S_MASK;
            p|=num;
            return p;
        }
    }
    puts("Invalid input. Better luck next time.");
    return 0;
}
unsigned int alignment(unsigned int p)
{
    int opt;
    printf("Select alignment:\nl)left   c)center   r)right\n");
    while((opt=tolower(getchar())))
    {
        eatline();
        while(strchr("lcr", opt)==NULL)
        {
            printf("Please enter a l, c or r: ");
            opt=tolower(getchar());
            eatline();
        }
        p&=~A_MASK;
        switch(opt)
        {
            case 'l'    : p|=LEFT; break;
            case 'c'    : p|=CENTER; break;
            case 'r'    : p|=RIGHT; break;
        }
        return p;
    }
    puts("Invalid input. Better luck next time.");
    return 0;
}