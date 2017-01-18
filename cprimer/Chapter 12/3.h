int setmode(int i);
float getinfo(int mod);
float showinfo(float fuel, int mod);

int setmode(int i)
{
    int mod = 0;
    if(i>1)
    {
        printf("Invalid input. Mode set to default, 0 for metric.\n");
    }
    else
        mod = i;
    return mod;
}

float getinfo(int mod)
{
    float fuel, dist;
    if(mod == 0)
    {
        printf("Enter distance travelled in kilometers: ");
        scanf("%f", &dist);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", &fuel);
        fuel = fuel/(dist/100);
    }
    if(mod == 1)
    {
        printf("Enter distance travelled in miles: ");
        scanf("%f", &dist);
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", &fuel);
        fuel = dist/fuel;
    }
    return fuel;
}

float showinfo(float fuel, int mod)
{
    if(mod == 0)
    {
        printf("Fuel consumption is %.2f liters per 100 km.\n", fuel);
    }
    if(mod == 1)
    {
        printf("Fuel consumption is %.2f miles per gallon.\n", fuel);
    }
    return fuel;
}