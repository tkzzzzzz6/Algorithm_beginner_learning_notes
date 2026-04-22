#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;
    bool flag = false;
    for (int year = 2014;year <= 2020;year++)
        for (int month = 1; month <= 12;month++)
            for (int day = 1; day <= 31;day++)
            {
                if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12);
                else if(month == 2)
                {
                    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
                        if(day > 29)
                            break;
                    }
                    else
                        if(day > 28)
                            break;
                }
                else
                    if(day > 30)
                        break;
                if(year == 2014 && month == 11 && day == 9){
                    flag = true;
                }
                if(flag){
                    cnt++;
                    if(cnt == 1001){
                        cout << setw(4) << setfill('0') << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day << endl;
                        return 0;
                    }
                }
            }
                return 0;
}