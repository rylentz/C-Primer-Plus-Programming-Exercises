#include<stdio.h>
#include<string.h>

int main(void)
{
    int letters;
    char word[40];
    printf("Give me a word, any word: ");
    scanf("%s", word);
    letters=strlen(word);
    while(letters>=0)
    {
        printf("%c", word[letters]);
        letters--;
    }
    printf("\n");
    return 0;
}