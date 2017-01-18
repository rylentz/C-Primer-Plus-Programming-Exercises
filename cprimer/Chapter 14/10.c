#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char * s_gets(char * st, int n);
char showmenu(void);
void eatline(void); // read through end of line
void show(void (* fp)(char *), char * str);
void ToUpper(char *); // convert string to uppercase
void ToLower(char *); // convert string to uppercase
void Transpose(char *); // transpose cases
int main(void)
{
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pfun[3])(char *)={ToUpper,ToLower,Transpose};
    puts("Enter a string (empty line to quit):");
    while (s_gets(line, LEN) != NULL && line[0] != '\0')
    {
        while ((choice = showmenu()) != 'n')
        {
            strcpy(copy, line);// make copy for show()
            switch (choice ) // switch sets pointer
            {
                case 'u' : show(pfun[0], copy); break;
                case 'l' : show(pfun[1], copy); break;
                case 't' : show(pfun[2], copy); break;
                case 'o' : printf("%s\n", copy);  break;
            }
        }
        puts("Enter a string (empty line to quit):");
    }
    puts("Bye!");
    return 0;
}
char showmenu(void)
{
    char ans;
    puts("Enter menu choice:");
    puts("u) uppercase l) lowercase");
    puts("t) transposed case o) original case");
    puts("n) next string");
    ans = getchar(); // get response
    ans = tolower(ans); // convert to lowercase
    eatline(); // dispose of rest of line
    while (strchr("ulton", ans) == NULL)
    {
        puts("Please enter a u, l, t, o, or n:");
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
void ToUpper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}
void ToLower(char * str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}
void Transpose(char * str)
{
    while (*str)
    {
        if (islower(*str))
            *str = toupper(*str);
        else if (isupper(*str))
            *str = tolower(*str);
        str++;
    }
}
void show(void (* fp)(char *), char * str)
{
    (*fp)(str); // apply chosen function to str
    puts(str); // display result
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