// 一个日期用 𝑌𝑌𝑌𝑌𝑀𝑀𝐷𝐷 的 8 位数字表示，其中前四位为年份，接着两位为月份，最后两位为日期。
#include<bits/stdc++.h>
using namespace std;

#define ll long long;

// 记录每个月的天数
int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 判断是否是闰年
bool is_leap_year(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool is_valid_date(int year,int month,int day){
    if(month < 1 || month > 12)
        return false;
    if(month == 2){
        if(is_leap_year(year)){
            return day <= 29;
        }
        else{
            return day <= 28;
        }
    }
    else{
        return day <= days_in_month[month - 1];
    }
    return true;
}

// 判断是否是回文日期
bool is_palindrome_date(int year,int month,int day){
    string date = to_string(year) + to_string(month) + to_string(day);
    string reversed_date = string(date.rbegin(), date.rend());
    return date == reversed_date;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string begin, end;
    cin >> begin >> end;

    // 一共是8位数字,前4位是年份,中间2位是月份,剩下2位是日期
    int begin_year = stoi(begin.substr(0, 4));
    int begin_month = stoi(begin.substr(4, 2));
    int begin_day = stoi(begin.substr(6, 2));

    int end_year = stoi(end.substr(0, 4));
    int end_month = stoi(end.substr(4, 2));
    int end_day = stoi(end.substr(6, 2));

    for (int year = begin_year; year <= end_year;++year){
        for (int month = 1; month <= 12;++month){
            if(month == 2 && is_leap_year(year)){
                for (int day = 1;day<=29;++day){
                    if(is_valid_date(year,month,day)){
                        if(is_palindrome_date(year,month,day)){
                            cout << year << month << day << endl;
                        }
                    }
                }
            }
            else if(month == 2 && !is_leap_year(year)){
                for (int day = 1;day<=28;++day){
                    if(is_valid_date(year,month,day)){
                        if(is_palindrome_date(year,month,day)){
                            cout << year << month << day << endl;
                        }
                    }
                }
            }
            else{
            for (int day = 1;day<=days_in_month[month - 1];++day){
                if(is_valid_date(year,month,day)){
                    if(is_palindrome_date(year,month,day)){
                        cout << year << month << day << endl;
                    }
                }
            }
        }
    }

        return 0;
}
