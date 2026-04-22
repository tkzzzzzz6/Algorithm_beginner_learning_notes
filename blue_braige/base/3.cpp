#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<string, int> mp;
    mp.emplace("Alex", 15);
    mp.emplace("Bob", 20);
    mp.emplace("Fiona", 5);
    map<string, int>::iterator it;
    for(it = mp.begin();it != mp.end();++it){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}