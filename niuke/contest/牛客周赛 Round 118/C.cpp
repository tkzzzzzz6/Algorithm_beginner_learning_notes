#include<bits/stdc++.h>
#define il inline
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5+5, mod = 1e9+7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

typedef struct{
    int x, y;
} Point;

il void solve(){
    vector<Point> points(4);
    int i = 0;
    for (; i < 2; ++i)
        cin >> points[i].x >> points[i].y;
    // x1 = x2时
    if(points[0].x == points[1].x){
        points[2].y = points[0].y;
        points[3].y = points[1].y;
        points[2].x = points[3].x = points[0].x + 1;
    }

    // y1 = y2时
    if(points[0].y == points[1].y){
        points[2].x = points[0].x;
        points[3].x = points[1].x;
        points[2].y = points[3].y = points[0].y + 1;
    }

    // 对角线的时候
    if(points[0].x != points[1].x && points[0].y != points[1].y){
        points[2].x = points[0].x;
        points[2].y = points[1].y;
        points[3].x = points[1].x;
        points[3].y = points[0].y;
    }

    for (; i < 4;++i)
        cout << points[i].x << ' ' << points[i].y << ' ';
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    

    solve();
    
    
    return 0;
}