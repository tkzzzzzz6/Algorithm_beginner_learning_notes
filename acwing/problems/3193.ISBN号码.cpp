/*
* @acwing app=acwing.cn id=3196 lang=C++
*
* 3193. ISBN号码
*/

// @acwing code start
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    string s;cin >> s;

    int n = s.size();
    int sum = 0;

    // 注意这里的终止判断是 i + 1 < n 或者写 i < n -1,最后一个数字是用来判断的
    for(int i = 0, j = 1;i+1<n;++i){
        if(s[i] != '-'){
            sum += (s[i] - '0')*j;
            ++j;
        }
    }

    sum %= 11;

    char c = sum + '0';
    if (sum == 10){
        c = 'X';
    }

    if(s.back() == c) puts("Right");
    else{
        s.back() = c;
        cout << s << endl;
    }
    
    return 0;
}


// @acwing code end
