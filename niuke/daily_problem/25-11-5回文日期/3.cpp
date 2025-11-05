#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int y, int m, int d)
{
    if (m < 1 || m > 12 || d < 1)
    {
        return false;
    }
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeap(y))
    {
        days_in_month[2] = 29;
    }
    return d <= days_in_month[m];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int start_date, end_date;
    cin >> start_date >> end_date;

    int start_year = start_date / 10000;
    int end_year = end_date / 10000;
    int count = 0;

    for (int y = start_year; y <= end_year; ++y)
    {
        // 构建对应的回文数并进行判断
        string y_str = to_string(y);
        string rev_y_str = y_str;
        reverse(rev_y_str.begin(), rev_y_str.end());

        int m = stoi(rev_y_str.substr(0, 2));
        int d = stoi(rev_y_str.substr(2, 4));

        if (isValidDate(y, m, d))
        {
            int palindrome_date = y * 10000 + m * 100 + d;
            if (palindrome_date >= start_date && palindrome_date <= end_date)
            {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
