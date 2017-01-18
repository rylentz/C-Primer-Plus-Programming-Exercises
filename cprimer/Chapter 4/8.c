#include <stdio.h>
#include <float.h>

int main(void)
{
    float gallons;
    float miles;
    
    printf("Enter miles traveled and gallons of gasoline consumed: \n");
    scanf("%f %f", &miles, &gallons);
    const float KILOMETERS = miles*1.609;
    const float LITERS = gallons*3.785;
    float mpg = miles/gallons;
    printf("MPG: %.1f\n", mpg);
    float lpkm = LITERS/(KILOMETERS/100);
    printf("Liters-per-100-km: %.1f\n", lpkm);
    return 0;
}