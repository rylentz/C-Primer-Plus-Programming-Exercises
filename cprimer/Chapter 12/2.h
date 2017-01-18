void set_mode(int i);
void get_info(void);
void show_info(void);
static int mod = 0;
static float dist, fuel;

void set_mode(int i)
{
    if(i>1)
    {
        printf("Invalid input. Mode will default to last valid mode choice or 0 in no valid input has yet been entered.\n");
    }
    else
        mod = i;
}

void get_info(void)
{
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
}

void show_info(void)
{
    if(mod == 0)
    {
        printf("Fuel consumption is %.2f liters per 100 km.\n", fuel);
    }
    if(mod == 1)
    {
        printf("Fuel consumption is %.2f miles per gallon.\n", fuel);
    }
}