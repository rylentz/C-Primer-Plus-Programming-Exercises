#include <stdio.h>
#include <math.h>
#define DEG_TO_RAD ((4 * atan(1))/180)
typedef struct polar_v {
    double magnitude;
    double angle;
} Polar_V;
typedef struct rect_v {
    double x;
    double y;
} Rect_V;
Rect_V polar_to_rect(Polar_V);
int main(void)
{
    Rect_V result;
    Polar_V input;
    puts("Enter the magnitude and angle (in degrees) of a vector; enter q to quit:");
    if(scanf("%lf %lf", &input.magnitude, &input.angle) == 2)
    {
        result = polar_to_rect(input);
        printf("x-coordinate = %0.2f, y-coordinate = %0.2f\n",
        result.x, result.y);
    }
    puts("Buh-bye.");
    return 0;
}
Rect_V polar_to_rect(Polar_V pv)
{
    Rect_V rv;
    pv.angle *= DEG_TO_RAD;
    rv.x = pv.magnitude*cos(pv.angle);
    rv.y = pv.magnitude*sin(pv.angle);
    return rv;
}