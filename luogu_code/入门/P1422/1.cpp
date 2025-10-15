#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double a[3] = {0.4463, 0.4663, 0.5663};
    cout << fixed << setprecision(1);
    if (n <= 150)
    {
        cout << a[0] * n << endl;
    }
    else if (n <= 400)
    {
        cout << a[0] * 150 + (n - 150) * a[1] << endl;
    }
    else
    {
        cout << a[0] * 150 + 250 * a[1] + (n - 400) * a[2] << endl;
    }
}
