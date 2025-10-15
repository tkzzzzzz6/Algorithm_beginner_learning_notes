#include <stdio.h>

bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main(void)
{
    int year;
    if (scanf("%d", &year) != 1) {
        fprintf(stderr, "Input error: please provide an integer.\n");
        return 1;
    }

    if (is_leap_year(year)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
