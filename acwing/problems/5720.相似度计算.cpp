/*
* @acwing app=acwing.cn id=5723 lang=C++
*
* 5720. 相似度计算
*/

// @acwing code start
#include <iostream>
#include <cstring>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<string> a,b,c; //用来保存两篇文章的单词数量以及a∪b的单词数量

int main(){

    int n,m;
    cin >> n >> m;

    string s;
    for(int i = 0;i<n;++i)
    {
        cin >> s;
        for(auto &c:s)c = tolower(c);
        a.insert(s);
        c.insert(s);
    }

    for(int i = 0;i<m;++i)
    {
        cin >> s;
        for(auto &c:s)c = tolower(c);
        b.insert(s);
        c.insert(s);
    }

    cout << a.size() + b.size() - c.size() << '\n'; // 容斥原理,a∩b = a + b - a∪b 
    cout << c.size() << '\n';

    return 0;
}

// @acwing code end
