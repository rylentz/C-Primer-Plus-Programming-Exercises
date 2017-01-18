#include<stdio.h>
#include<string.h>
#include<ctype.h>
//alignment options
#define LEFT 0
#define CENTER 1
#define RIGHT 2
struct font{
    unsigned int id     : 8;
    unsigned int size   : 7;
    unsigned int        : 1;
    unsigned int align  : 2;
    unsigned int        : 6;
    unsigned int bold   : 1;
    unsigned int italic : 1;
    unsigned int under  : 1;
    unsigned int        : 5;
};
void show(const struct font *p);
void eatline(void);
void type(struct font *p);
void size(struct font *p);
void alignment(struct font *p);

int main(void)
{
    struct font f={22, 122, LEFT, 0, 0, 0};
    char opt;
    show(&f);
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
            case 'f'    : type(&f); break;
            case 's'    : size(&f); break;
            case 'a'    : alignment(&f); break;
            case 'b'    : f.bold^=1; break;
            case 'i'    : f.italic^=1; break;
            case 'u'    : f.under^=1; break;
            case 'q'    : puts("Buh-bye."); return 0;
        }
        show(&f);
        puts("Which font parameter would you like to modify?");
        puts("f)font   s)size   a)alignment   b)toggle bold   i)toggle italics   u)toggle underline   q)quit");
    }
    puts("Buh-bye.");
    return 0;
}

void show(const struct font *p)
{
    printf(" ID SIZE ALIGNMENT   B   I   U\n");
    printf("%3d %3d", p->id, p->size);
    switch(p->align)
    {
        case LEFT   : printf("     left"); break;
        case CENTER : printf("   center"); break;
        case RIGHT  : printf("    right"); break;
    }
    printf("    %s", p->bold==0? "off":"on");
    printf(" %s", p->italic==0? "off":"on");
    printf(" %s\n", p->under==0? "off":"on");
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
void type(struct font *p)
{
    int num;
    printf("Enter the new font ID(0-255): ");
    while((scanf("%d", &num))==1)
    {
        eatline();
        if(num<0 || num>255)
            printf("Please enter a number from 0 to 255: ");
        else
        {
            p->id=num;
            return;
        }
    }
    puts("Invalid input. Better luck next time.");
}
void size(struct font *p)
{
    int num;
    printf("Enter the new font size(0-127): ");
    while((scanf("%d", &num))==1)
    {
        eatline();
        if(num<0 || num>127)
            printf("Please enter a number from 0 to 127: ");
        else
        {
            p->size=num;
            return;
        }
    }
    puts("Invalid input. Better luck next time.");
}
void alignment(struct font *p)
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
        switch(opt)
        {
            case 'l'    : p->align=LEFT; break;
            case 'c'    : p->align=CENTER; break;
            case 'r'    : p->align=RIGHT; break;
        }
        return;
    }
    puts("Invalid input. Better luck next time.");
}