#include <iostream>
#include <ctime>

using namespace std;

bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0 || (year % 400 == 0));
}

int day_in_month(int year, int month)
{
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year))
    {
        return 29;
    }
    return days_in_month[month - 1];
}

int main()
{
    int year, month;
    std::cin >> year >> month;
    std::cout << day_in_month(year, month) << std::endl;
    return 0;
}