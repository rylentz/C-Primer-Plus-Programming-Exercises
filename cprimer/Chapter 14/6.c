#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define PLAYERS 9
struct stats
{
    char first[MAX];
    char last[MAX];
    int atbats;
    int hits;
    int walks;
    int rbis;
    float batavg;
};

int main(void)
{
    struct stats player[PLAYERS] =
    {
        {"","",0,0,0,0,0},{"","",0,0,0,0,0},{"","",0,0,0,0,0},{"","",0,0,0,0,0},{"","",0,0,0,0,0},{"","",0,0,0,0,0},
        {"","",0,0,0,0,0},{"","",0,0,0,0,0},{"","",0,0,0,0,0}
    };
    FILE *fp;
    int tnum, tatbats, thits, twalks, trbis, line, i;
    float tbatavg;
    char tfirst[MAX], tlast[MAX];
    if((fp=fopen("wombats", "r"))==NULL)
    {
        printf("Can't open %s\n", "wombats");
        exit(EXIT_FAILURE);
    }
    for(line=0; fscanf(fp, "%d %s %s %d %d %d %d", &tnum, tfirst, tlast, &tatbats, &thits, &twalks, &trbis)==7; line++)
    {
        player[tnum-1].atbats += tatbats;
        player[tnum-1].hits += thits;
        player[tnum-1].walks += twalks;
        player[tnum-1].rbis += trbis;
        player[tnum-1].batavg = (float)player[tnum-1].hits/player[tnum-1].atbats;
        for(i=0; i<MAX; i++)
        {
            player[tnum-1].first[i] = tfirst[i];
            player[tnum-1].last[i] = tlast[i];
        }
    }
    fclose(fp);
    printf("Player #   First Name          Last Name       At Bats   Hits   Walks   RBIs   Batter Avg.\n");
    for(line=0; line<PLAYERS; line++)
    {
        printf("%4d       %-20s%-20s%-9d", line+1, player[line].first, player[line].last, player[line].atbats); 
        printf("%-7d%-7d%-7d%-7.2f\n", player[line].hits, player[line].walks, player[line].rbis, player[line].batavg);
    }
    tatbats=0; 
    thits=0; 
    twalks=0;
    trbis=0;
    tbatavg=0;
    for(line=0; line<PLAYERS; line++)
    {
        tatbats += player[line].atbats;
        thits += player[line].hits;
        twalks += player[line].walks;
        trbis += player[line].rbis;
    }
    tbatavg = (float)thits/tatbats;
    printf("                              Team Stats:         %d%8d%7d%7d%10.2f\n", tatbats, thits, twalks, trbis, tbatavg);
    return 0;
}