/*
* @acwing app=acwing.cn id=3195 lang=C++
*
* 3192. 出现次数最多的数
*/

// @acwing code start

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;cin >> n;
    vector<int> s(n);
    
    for(int i =0;i<n;++i){
        cin >> s[i];
    }

    sort(s.begin(),s.end());

    int res = 0,maxlen = 0;
    int i = 0;
    while(i < n){
        int j = i + 1;
        while(j < n && s[i] == s[j])j++;
        if(maxlen < j - i)res = s[i],maxlen = j - i;
        i = j; //手动跳过已经统计的重复元素,这里使用 for循环不要加上++i,不然有元素会跳过,等效于下面的 for 循环
    }

    // for(int i =0;i<n;){
        // ...
    // }

    cout << res << endl;

    return 0;
}


// @acwing code end
