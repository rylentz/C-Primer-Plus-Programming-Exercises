#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define CAP 12
#define MAX 30
struct seat{
    int id;
    int status;
    char last[MAX];
    char first[MAX];
};
char * s_gets(char * st, int n);
char showmenu(void);
void eatline(void);
void empty(struct seat *p);
void emptylist(struct seat *p);
void alpha(struct seat *p);
void assign(struct seat *p);
void alphalist(struct seat *p);
void del(struct seat *p);

int main(void)
{
    struct seat pass[CAP]={
        {.id=1, .status=0},{.id=2, .status=0},{.id=3, .status=0},{.id=4, .status=0},{.id=5, .status=0}, {.id=6, .status=0},
        {.id=7, .status=0},{.id=8, .status=0},{.id=9, .status=0},{.id=10, .status=0},{.id=11, .status=0},{.id=12, .status=0}
    };
    int count=0;
    char ans;
    FILE *fp;
    int size = sizeof(struct seat);
    if ((fp = fopen("seats.dat", "r+b")) == NULL)
    {
        fputs("Can't open book.dat file\n",stderr);
        exit(1);
    }
    rewind(fp);
    for(count=0; count<CAP; count++)
        fread(&pass[count], size, 1, fp);
    while((ans=showmenu())!='f')
    {
        switch(ans)
        {
            case 'a':   empty(pass);        break;
            case 'b':   emptylist(pass);    break;
            case 'c':   alphalist(pass);    break;
            case 'd':   assign(pass);       break;
            case 'e':   del(pass);          break;
        }
        fwrite(&pass[0], size, count, fp);
        rewind(fp);
    }
    fclose(fp);
    return 0;
}

char showmenu(void)
{
    char ans;
    puts("Please choose from the menu below:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
    ans = getchar(); // get response
    ans = tolower(ans); // convert to lowercase
    eatline(); // dispose of rest of line
    while (strchr("abcdef", ans) == NULL)
    {
        puts("Please enter a, b, c, d, e, or f:");
        ans = tolower(getchar());
        eatline();
    }
    return ans;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            eatline();
    }
    return ret_val;
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void empty(struct seat *p)
{
    int num=0, i;
    for(i=0; i<CAP; i++)
    {
        if(p[i].status==0)
            num++;
    }
    printf("Number of Seats Available: %d\n", num);
}

void emptylist(struct seat *p)
{
    int i;
    printf("Seats Available:");
    for(i=0; i<CAP; i++)
    {
        if(p[i].status==0)
            printf("  %d", p[i].id);
    }
    printf("\n");
}

void alphalist(struct seat *p)
{
    int i;
    struct seat copy[CAP];
    for(i=0; i<CAP; i++)
        copy[i]=p[i];
    printf("Passenger Seating Assignment:\n");
    alpha(copy);
    for(i=0; i<CAP; i++)
    {
        if(copy[i].status==1)
            printf("%s, %s - Seat %d\n", copy[i].last, copy[i].first, copy[i].id);
    }
    printf("\n");
}
void alpha(struct seat *c)
{
    struct seat temp;
    int top, seek;
    for (top = 0; top < CAP-1; top++)
        for (seek = top + 1; seek < CAP; seek++)
            if (strcmp(c[top].last, c[seek].last) > 0)
            {
                temp = c[top];
                c[top] = c[seek];
                c[seek] = temp;
            }
}

void assign(struct seat *p)
{
    int seat;
    puts("Please choose from one of the following available seats.");
    emptylist(p);
    puts("Which seat would you like? (Enter 0 to abort)");
    scanf("%d", &seat);
    eatline();
    if(seat==0)
        return;
    while((seat>=1) && (seat<=12) && (p[seat-1].status!=0))
    {
        printf("Seat %d is unavailable.\n", seat);
        puts("Please choose from one of the following available seats.");
        emptylist(p);
        puts("Which seat would you like? (Enter 0 to abort)");
        scanf("%d", &seat);
        eatline();
        if(seat==0)
            return;
    }
    printf("Please enter the first name of the passenger: ");
    s_gets(p[seat-1].first, MAX);
    printf("Now enter the last name of the passenger: ");
    s_gets(p[seat-1].last, MAX);
    p[seat-1].status = 1;
    printf("Passenger %s %s has been assigned to seat %d\n", p[seat-1].first, p[seat-1].last, p[seat-1].id);
}

void del(struct seat *p)
{
    int seat;
    puts("Please choose one of the following seat assignments to delete.");
    alphalist(p);
    puts("Enter the seat number of the assignment you would like to delete (0 to abort).");
    scanf("%d", &seat);
    eatline();
    if(seat==0)
        return ;
    while((seat>=1) && (seat<=12) && (p[seat-1].status!=1))
    {
        printf("Seat assignment %d is already empty.\n", seat);
        puts("Please choose one of the following seat assignments to delete.");
        alphalist(p);
        puts("Enter the seat number of the assignment you would like to delete (0 to abort).");
        scanf("%d", &seat);
        eatline();
        if(seat==0)
            return ;
    }
    strcpy(p[seat-1].first, "");
    strcpy(p[seat-1].last, "");
    p[seat-1].status = 0;
    printf("Seat %d is now empty.", seat);
}