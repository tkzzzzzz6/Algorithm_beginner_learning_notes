#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;
    bool flag = false;
    for (int year = 1921; year <= 2020; year++)
        for (int month = 1; month <= 12; month++)
            for (int day = 1; day <= 31; day++)
            {
                if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12);
                else if (month == 2)
                {
                    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                    {
                        if (day > 29)
                            break;
                    }
                    else if (day > 28)
                        break;
                }
                else if (day > 30)
                    break;
                if (year == 1921 && month == 7 && day == 23)
                {
                    flag = true;
                    cnt = 0;
                }
                if (flag)
                {
                    if (year == 2020 && month == 7 && day == 1)
                    {
                        cout << cnt*24*60 << endl;
                        return 0;
                    }
                    cnt++;
                }
            }
    return 0;
}