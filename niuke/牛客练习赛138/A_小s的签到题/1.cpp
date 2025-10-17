#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<char> ids(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> ids[i];
    }
    int max_pass = -1;
    char ans = 'Z' + 1;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        int div = s.find('/');
        int a = stoi(s.substr(0, div));
        if (a > max_pass || (a == max_pass && ids[i] < ans))
        {
            max_pass = a;
            ans = ids[i];
        }
    }
    cout << ans << endl;
    return 0;
}