#define LEN 10
struct month{
    char name[LEN];
    char abr[4];
    int days;
    int num;
};
struct month months[12] =
{
    {"january", "jan", 31, 1},
    {"february", "feb", 28, 2},
    {"march", "mar", 31, 3},
    {"april", "apr", 30, 4},
    {"may", "may", 31, 5},
    {"june", "jun", 30, 6},
    {"july", "jul", 31, 7},
    {"august", "aug", 31, 8},   
    {"september", "sep", 30, 9},
    {"october", "oct", 31, 10},
    {"november", "nov", 30, 11},
    {"december", "dec", 31, 12}
};