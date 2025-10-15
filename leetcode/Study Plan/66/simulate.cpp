#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
    public:
    vector<int> add(vector<int> &a, vector<int> &b){
        int n = a.size(), m = b.size();
        vector<int> c;
        int carry = 0;
        for (int i = n - 1, j = m - 1; i >= 0 || j >= 0; i--, j--){
            int ai = (i >= 0) ? a[i] : 0;
            int bj = (j >= 0) ? b[j] : 0;
            int sum = ai + bj + carry;
            carry = sum / 10;
            c.push_back(sum % 10);
        }
        if(carry)
            c.push_back(carry);
        reverse(c.begin(), c.end());
        return c;
    }
};

int main(){
    Solution s;
    string sa, sb;
    cin >> sa >> sb;
    vector<int> a, b;
    for(auto c : sa) a.push_back(c - '0');
    for(auto c : sb) b.push_back(c - '0');
    auto c = s.add(a, b);
    for(auto x : c) cout << x;
    return 0;
}
