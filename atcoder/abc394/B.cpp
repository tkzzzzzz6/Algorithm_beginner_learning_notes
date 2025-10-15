// 包含C++标准库的头文件
#include <bits/stdc++.h>

// 使用标准命名空间
using namespace std;

int main(){
    // 声明变量n用于存储输入的字符串个数
    int n;
    cin >> n;
    // 创建一个大小为n的字符串向量s用于存储输入的字符串
    vector<string> s(n);
    // 循环读入n个字符串
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    // 创建一个pair向量a,用于存储字符串及其长度
    vector<pair<string,int>> a;
    // 遍历字符串向量s,将每个字符串及其长度作为pair存入向量a
    for(int i = 0; i < n; i++){
        a.push_back(make_pair(s[i],s[i].size()));
    }
    // 使用lambda表达式对向量a按照字符串长度进行升序排序
    // sort(a.begin(), a.end(), [](const pair<string,int>& x, const pair<string,int>& y){
    //     return x.second < y.second;
    // });
    // const 和 & 是为了提高效率，可以暂时不用太关注
    sort(a.begin(), a.end(), [](pair<string, int> x, pair<string, int> y)
         { return x.second < y.second; });
    // 按顺序输出排序后的字符串
    for(int i = 0; i < n; i++){
        cout << a[i].first;
    }
    return 0;
}
