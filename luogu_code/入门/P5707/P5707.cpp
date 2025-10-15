#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int s,v;

int main(){
    cin >> s >> v;
    int t = ceil((double)s/v + 10);

    int current_hour = 8;
    int current_minute = 0;

    //calculate the latest time 
    int total_minutes = current_hour * 60 + current_minute - t;
    if (total_minutes < 0){
        total_minutes += 24 * 60;
    }

    int departure_hour = total_minutes / 60;
    int departure_minute = total_minutes % 60;

    //formatting the output
    cout << setfill('0')<<setw(2)<<departure_hour<<":"
        <<setfill('0')<<setw(2)<<departure_minute<<endl;
    return 0;
}
