/*
* @acwing app=acwing.cn id=3215 lang=C++
*
* 3212. 图像旋转
*/

// @acwing code start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> a;

// 逆时针旋转 90 度等效于 转置 + 按行翻转

int main(){
    int n,m;
    cin >> n >> m;
    
    // 输出的时候,行和列换个位置,实现转置的功能,所以注意这里的 resize
    a.resize(m,vector<int>(n));
    for(int i = 0;i<n;++i){
        for(int j =0;j<m;++j){
            cin >> a[j][i];
        }
    }

    // 按行翻转
    reverse(a.begin(),a.end());

    n = a.size();
    m = a[0].size();

    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


// @acwing code end
