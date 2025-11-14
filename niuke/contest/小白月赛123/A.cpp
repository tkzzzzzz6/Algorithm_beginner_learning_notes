#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string> people = {
    "Kato_Shoko",
    "koishiYun",
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t,x;
    cin >> t;
    while(t--)
    {
        cin >> x;

        switch(x){
            case 1:
            case 2:
                cout << people[0] << endl;
                break;
            case 3:
                cout << people[1] << endl;
                break;
            case 4:
            case 5:
                cout << people[0] << endl;
                break;
            case 6:
                cout << people[1] << endl;
                break;
        }

    }
    
    return 0;
}