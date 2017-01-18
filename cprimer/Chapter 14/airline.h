#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define CAP 12
#define MAX 30
struct seat{
    int id;
    int status;
    int confirm;
    char last[MAX];
    char first[MAX];
};
char * s_gets(char * st, int n);
char flightmenu(void);
char showmenu(int fnum);
void eatline(void);
void empty(struct seat *p);
void emptylist(struct seat *p);
void alpha(struct seat *p);
void assign(struct seat *p);
void alphalist(struct seat *p);
void del(struct seat *p);
void confirm(struct seat *p);

char flightmenu(void)
{
    int flight;
    puts("Please choose a flight:");
    puts("1) Flight 102   2) Flight 311   3) Flight 444   4) Flight 519   5) Quit");
    flight=getchar();
    eatline();
    while (strchr("12345", flight) == NULL)
    {
        puts("Please enter 1, 2, 3, 4, or 5:");
        flight=getchar();
        eatline();
    }
    return flight;
}
char showmenu(int fnum)
{
    char ans;
    printf("For Colossus Airlines Flight %d, please choose from the menu below:\n", fnum);
    puts("1) Show number of empty seats");
    puts("2) Show list of empty seats");
    puts("3) Show alphabetical list of seats");
    puts("4) Assign a customer to a seat assignment");
    puts("5) Confirm a seat assignment");
    puts("6) Delete a seat assignment");
    puts("7) Exit to flight menu");
    ans = getchar(); // get response
    eatline(); // dispose of rest of line
    while (strchr("1234567", ans) == NULL)
    {
        puts("Please enter 1, 2, 3, 4, 5, 6, or 7:");
        ans = getchar();
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
        {
            printf("%s, %s - Seat %d ", copy[i].last, copy[i].first, copy[i].id);
            if(copy[i].confirm==1)
                printf("Confirmed");
            printf("\n");
        }
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
    p[seat-1].confirm = 0;
    printf("Seat %d is now empty.", seat);
}
void confirm(struct seat *p)
{
    int seat;
    puts("Here is a list of the current seat assignments:");
    alphalist(p);
    puts("Enter the seat number of the assignment you would like to confirm (0 to abort).");
    scanf("%d", &seat);
    eatline();
    if(seat==0)
        return ;
    while((seat>=1) && (seat<=12) && (p[seat-1].confirm!=0))
    {
        printf("Seat assignment %d is already confirmed.\n", seat);
        puts("Please choose one of the following seat assignments to confirm.");
        alphalist(p);
        puts("Enter the seat number of the assignment you would like to confirm (0 to abort).");
        scanf("%d", &seat);
        eatline();
        if(seat==0)
            return ;
    }
    p[seat-1].confirm=1;
    printf("Seat %d is now confirmed.\n", seat);
}