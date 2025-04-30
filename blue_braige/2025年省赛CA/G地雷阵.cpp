#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<double, double>> radians;
    for (int i = 0; i < n;++i){
        double a, b, r;
        cin >> a >> b >> r;
        double theta = atan2(b,a);
        double len = sqrt(a * a + b * b);
        double phi = asin(r / len);
        radians.emplace_back(theta - phi, theta + phi);
    }
    sort(radians.begin(), radians.end());
    double start = 0, end = 0, sum = 0;
    for (auto &[l,r]:radians){
        if(l > end){
            sum += end - start;
            start = l;
            end = r;
        }
    }
    sum += end - start;
    cout << fixed << setprecision(2) << sum << endl;
    return 0;
}
