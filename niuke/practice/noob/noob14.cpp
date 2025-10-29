
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Point {
private:
    double x, y;
public:
    Point(double px, double py) :x(px), y(py) {}
    double get_euclideanDistance(const Point& p2) const {
        double dx = x - p2.x;
        double dy = y - p2.y;
        return sqrt(dx * dx + dy * dy);
    }

    double get_manhattanDistance(const Point p2)const {
        return abs(x - p2.x) + abs(y - p2.y);
    }
};


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int x, y;
    cin >> x >> y;
    Point p1(x, y);
    cin >> x >> y;
    Point p2(x, y);

    cout << fixed << setprecision(10) << fabs(p1.get_euclideanDistance(p2) - p1.get_manhattanDistance(p2));

    return 0;
}