/*
 * @acwing app=acwing.cn id=3202 lang=C++
 *
 * 3199. 命令行选项
 */

// @acwing code start
#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

const int N = 30;
bool o1[N],o2[N]; // 用来判断是无参数选项还是有参数选项
string ans[N]; // 用来保存有参数选项的参数


int main(){
    //读取选项并判断选项类型
    string str;cin >> str;
    for(int i = 0;i<str.size();++i){
        if(i+1<str.size() && str[i+1] == ':'){
            o2[str[i] - 'a'] = true;
            ++i;
        }else{
            o1[str[i] - 'a'] = true;
        }
    }

    int n;cin >> n;
    getchar(); // 过滤 n 后面的回车
    for(int c = 1;c<=n;++c){
        printf("Case %d:",c);
        getline(cin,str);
        stringstream scin(str);
        vector<string> ops;
        while(scin >> str)ops.push_back(str);
        for(int i = 0;i<26;++i)ans[i].clear(); //注意每次都需要将 ans 清空

        // 存储有参数选项的参数,第一个ops是 ls 可以直接跳过
        for(int i=1;i<ops.size();++i){
            if(ops[i][0] != '-' || ops[i][1] < 'a' || ops[i][1] >'z' || ops[i].size()!=2)break;
            int k = ops[i][1] - 'a';
            if(o1[k] ){
                ans[k] = '*';
            }else if(o2[k] && i+1<ops.size()){
                ans[k] = ops[i+1];
                ++i;
            }else
                break;
        }

        for(int i = 0;i<26;++i){
            if(ans[i].size()){
                cout << " -" << (char)('a'+i);
                if(o2[i])cout <<" "<< ans[i];
            }
        }

        cout << endl;
    }

    return 0;
}

// @acwing code end
