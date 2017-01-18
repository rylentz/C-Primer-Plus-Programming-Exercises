#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10 /* maximum number of books */
char * s_gets(char * st, int n);
struct book { /* set up book template */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
char showmenu(void);
void eatline(void);
struct book modify(struct book library);

int main(void)
{
    struct book library[MAXBKS]; /* array of structures */
    int count = 0;
    int index, filecount;
    char ans;
    FILE * pbooks;
    int size = sizeof (struct book);
    if ((pbooks = fopen("book.dat", "r+b")) == NULL)
    {
        fputs("Can't open book.dat file\n",stderr);
        exit(1);
    }
    rewind(pbooks); /* go to start of file */
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n",library[count].title, library[count].author, library[count].value);
        ans=showmenu();
        if(ans=='k')
        {
            count++;
            continue;
        }
        else if(ans=='m')
        {
            library[count]=modify(library[count]);
            count++;
        }
        else if(ans=='d')
            library[count]=library[count+1];
    }
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);
        eatline();
        if (count < MAXBKS)
            puts("Enter the next title.");
    }
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n",library[index].title,
        library[index].author, library[index].value);
        fclose(pbooks);
        pbooks=fopen("book.dat", "w");
        fwrite(&library[0], size, count, pbooks);
        fclose(pbooks);
    }
    else
    {    
        pbooks=fopen("book.dat", "w");
        fclose(pbooks);
        puts("No books? Too bad.\n");
    }
    puts("Bye.\n");
    return 0;
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
char showmenu(void)
{
    char ans;
    puts("Would you like to [k] keep, [m] modify, or [d] delete this record?");
    ans = getchar(); // get response
    ans = tolower(ans); // convert to lowercase
    eatline(); // dispose of rest of line
    while (strchr("kmd", ans) == NULL)
    {
        puts("Please enter a k, m, or d:");
        ans = tolower(getchar());
        eatline();
    }
    return ans;
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

struct book modify(struct book library)
{
    puts("Please enter the modified title:");
    s_gets(library.title, MAXTITL);
    puts("Now enter the modified author:");
    s_gets(library.author, MAXAUTL);
    puts("Now enter the modified value:");
    scanf("%f", &library.value);
    eatline();
    return library;
}