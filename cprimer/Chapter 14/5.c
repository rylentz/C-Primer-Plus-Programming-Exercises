#include<stdio.h>
#define CSIZE 4
#define MAX 20
struct name 
{
    char first[MAX];
    char last[MAX];
};
struct student
{
    struct name names;
    float grade[3];
    float avg;
};
void scores(struct student work[], int num);
void avgs(struct student work[], int num);
void show(struct student work[], int num);

int main(void)
{
    struct student quatro[CSIZE] = 
    {
        {.names = {"Ryan", "Lentz"}},
        {.names = {"Jenny", "May"}},
        {.names = {"Frank", "Grape"}},
        {.names = {"Jeff", "Besos"}}
    };
    scores(quatro, CSIZE);
    avgs(quatro, CSIZE);
    show(quatro, CSIZE);
    return 0;
}

void scores(struct student work[], int num)
{
    int i;
    for(i=0; i<num; i++)
    {
        printf("Please enter 3 scores for %s %s: ", work[i].names.first, work[i].names.last);
        while(scanf("%f %f %f", &work[i].grade[0], &work[i].grade[1], &work[i].grade[2])!=3)
            printf("Invalid input. Please enter 3 scores separated by spaces and then press [enter]: ");
    }
}

void avgs(struct student work[], int num)
{
    int i;
    for(i=0; i<num; i++)
        work[i].avg = (work[i].grade[0]+work[i].grade[1]+work[i].grade[2])/3;
}

void show(struct student work[], int num)
{
    int i;
    for(i=0; i<num; i++)
    {
        printf("Student: %s, %s\n", work[i].names.last, work[i].names.first);
        printf("Grades: %g, %g, %g\n", work[i].grade[0], work[i].grade[1], work[i].grade[2]);
        printf("Average Grade: %g\n", work[i].avg);
    }
}