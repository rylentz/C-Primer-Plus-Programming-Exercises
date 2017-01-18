#include <stdio.h>
#include "3.h"
int main(void)
{
    int mode;
    float gas;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        mode = setmode(mode);
        gas = getinfo(mode);
        showinfo(gas, mode);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}