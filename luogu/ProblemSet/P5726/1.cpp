#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<limits.h>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int max = 0,min = INT16_MAX;
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin >> x;
        sum += x;
        if(x > max)max = x;
        if(x < min)min = x;
    }
    sum -= (max + min);
    int average = sum / (n-2);
    cout << fixed << setprecision(2) << average << endl;

    return 0;
}
