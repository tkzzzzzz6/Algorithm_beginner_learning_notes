#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct point{
    double x, y;
}point;

double cal_distance(point p1, point p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double cal_circumference(point p1, point p2, point p3){
    return cal_distance(p1, p2) + cal_distance(p2, p3) + cal_distance(p3, p1);
}

int main(){
    point p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    cout << fixed << setprecision(2) << cal_circumference(p1, p2, p3) << endl;
    return 0;
}

