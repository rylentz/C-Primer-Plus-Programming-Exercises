/* manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 /* maximum number of books */
struct book { /* set up book template */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
void alpha(struct book strings[], int num);
void price(struct book strings[], int num);


int main(void)
{
    struct book library[MAXBKS]; /* array of book structures */
    int count = 0;
    int index;
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue; /* clear input line */
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0)
    {
        printf("Here is the list of your books in the order you entered them:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        printf("Now here is the list of your books in alphabetical order:\n");
        alpha(library, count);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        printf("Now here is the list of your books in order of increasing value:\n");
        price(library, count);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
    }
    else
        printf("No books? Too bad.\n");
    return 0;
}

void alpha(struct book strings[], int num)
{
    struct book temp;
    int top, seek;
    for (top = 0; top < num-1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top].title, strings[seek].title) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

void price(struct book strings[], int num)
{
    struct book temp;
    int top, seek;
    for (top = 0; top < num-1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strings[top].value > strings[seek].value)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
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
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}