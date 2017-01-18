3.
struct month{
    char name[12];
    char abr[4];
    int days;
    int num;
};
4.
struct month months[12] =
{
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};
5.
int dayssofar(int mon)
{
    int i;
    int days;
    if(mon<1 || mon>12)
        return(-1); //error signal
    for(i=0, days=0; i<mon; i++)
        days+=month[i].days;
    return days;
}
6a.
LENS glasses[10];
glasses[2].foclen = 500;
glasses[2].fstop = 2.0;
strcpy(glasses[2].brand, "Remarkatar");
6b.
LENS glasses[10] = { [2] = {500, 2.0, "Remarkatar"}};

7a.
6
Arcturan
cturan
7b.
deb.title.last
pb->title.last
7c.
#include"starfolk.h"
void show(const struct bem *creature)
{
    printf("%s %s is a %d-limbed %s.\n", creature->title.first, creature->title.last, creature->limbs, creature->type);
}
8a. willie.born   b. pt->born   c. scanf("%d", &willie.born);   d. scanf("%d", &pt->born);   e. scanf("%s", &willie.name.lname);
f. scanf("%s", &pt->name.lname);   g. willie.name.fname[2]   h. int letters = strlen(willie.name.fname)+strlen(willie.name.lname);
9.
struct car{
    char name[20];
    int hp;
    double mpg;
    double wb;
    int year;
};
10a.
struct calcmpg(struct gas calc)
{
    if(calc.gals>0)
        calc.mpg=calc.distance/calc.gals;
    else
        calc.mpg=-1.0 //error message
    return calc;
}
b.
void calcmpg(struct gas *calc)
{
    if(calc->gals>0)
        calc->mpg=calc->distance/calc->gals;
    else
        calc->mpg=-1.0 //error message
}
11.
enum choices {no, yes, maybe};
12.
char * (*pf) (char *, char)
13.
double one(double a, double b);
double two(double a, double b);
double three(double a, double b);
double four(double a, double b);
double (*pf[4])(double, double) = {one, two, three, four};
pf[1]=&two;
pf[1](10.0,2.5);
(*pf[1])(10.0; 2.5);


