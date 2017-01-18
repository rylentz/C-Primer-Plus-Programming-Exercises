#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include"airline.h"

int main(void)
{
    struct seat pass[CAP]={
        {.id=1,.status=0,.confirm=0},{.id=2,.status=0,.confirm=0},{.id=3,.status=0,.confirm=0},{.id=4,.status=0,.confirm=0},
        {.id=5,.status=0,.confirm=0},{.id=6,.status=0,.confirm=0},{.id=7,.status=0,.confirm=0},{.id=8,.status=0,.confirm=0},
        {.id=9,.status=0,.confirm=0},{.id=10,.status=0,.confirm=0},{.id=11,.status=0,.confirm=0},{.id=12,.status=0,.confirm=0}
    };
    int count;
    int fnum;
    char flight, ans;
    FILE *fp;
    int size = sizeof(struct seat);
    while((flight=flightmenu())!='5')
    {
        if(flight=='1')
        {
            fnum=102;
            if((fp = fopen("f102.dat", "r+b")) == NULL)
            {
                fputs("Can't open book.dat file\n",stderr);
                exit(1);
            }
            rewind(fp);
            for(count=0; count<CAP; count++)
                fread(&pass[count], size, 1, fp);
        }
        else if(flight=='2')
        {
            fnum=311;
            if((fp = fopen("f311.dat", "r+b")) == NULL)
            {
                fputs("Can't open book.dat file\n",stderr);
                exit(1);
            }
            rewind(fp);
            for(count=0; count<CAP; count++)
                fread(&pass[count], size, 1, fp);
        }    
        else if(flight=='3')
        {
            fnum=444;
            if((fp = fopen("f444.dat", "r+b")) == NULL)
            {
                fputs("Can't open book.dat file\n",stderr);
                exit(1);
            }
            rewind(fp);
            for(count=0; count<CAP; count++)
                fread(&pass[count], size, 1, fp);
        }
        else if(flight=='4')
        {
            fnum=519;
            if((fp = fopen("f519.dat", "r+b")) == NULL)
            {
                fputs("Can't open book.dat file\n",stderr);
                exit(1);
            }
            rewind(fp);
            for(count=0; count<CAP; count++)
                fread(&pass[count], size, 1, fp);
        }    
        while((ans=showmenu(fnum))!='7')
        {
            switch(ans)
            {
                case '1':   empty(pass);        break;
                case '2':   emptylist(pass);    break;
                case '3':   alphalist(pass);    break;
                case '4':   assign(pass);       break;
                case '5':   confirm(pass);      break;
                case '6':   del(pass);          break;
            }
            fwrite(&pass[0], size, CAP, fp);
            rewind(fp);
        }
        fclose(fp);
    }
    return 0;
}