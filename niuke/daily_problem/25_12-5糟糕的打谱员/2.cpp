// 编译优化指令，提高代码运行速度
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")

// 头文件包含
# include<iostream>
# include<iomanip>
# include<algorithm>
# include<cmath>
# include<cstdio>
# include<set>
# include<stack>
# include<queue> 
# include<map>
# include<string>
# include<cstring> 
 
// 宏定义
# define eps 1e-9
# define fi first
# define se second
# define ll long long
# define int ll
// cout<<fixed<<setprecision(n) 
using namespace std;
 
// 类型定义
typedef unsigned long long ull;
typedef pair<int,int > PII; 

// 常量定义
const int mod=1e9+7;
const int MAX=1e5+10;        // 最大数组长度
const int Time=86400;
const int X=131;
const int inf=0x3f3f3f3f;
const double PI = 1e-4;
double pai = 3.14159265358979323846; 

// 全局变量
int T,n;                     // T: 测试用例数量, n: 每个测试用例的元素个数
int dp[MAX];                 // dp[i]: 以第i个位置结尾的最长合法序列长度
int pre[2][15];              // pre[j][k]: 颜色为j、数值为k的最后一个位置索引
                              // j: 颜色(0或1), k: 数值(1-10)

/**
 * 解题思路：动态规划
 * 问题：找到最长的序列，使得相邻两个元素颜色不同且数值不同
 * 
 * 状态定义：
 *   - dp[i]: 以第i个位置结尾的最长合法序列长度
 *   - pre[j][k]: 颜色为j、数值为k的最后一个位置索引
 * 
 * 转移方程：
 *   对于当前位置(c, a)，找到所有颜色不同(j != c)且数值不同(k != a)的前驱位置
 *   dp[i] = max(dp[pre[j][k]] + 1)，其中 j != c 且 k != a
 */
void solve(){
	  int ans = 0;                    // 记录全局最长序列长度
      cin >> n;                       // 输入元素个数
      
      // 初始化dp数组和pre数组
      memset(dp,0,sizeof dp);
      memset(pre,0,sizeof pre);
      
      // 遍历每个输入的元素
      for(int i = 1 ; i <= n  ; i ++ ){
      	  int c, a;                    // c: 颜色(0或1), a: 数值(1-10)
      	  cin >> c >> a;
      	  
      	  // 遍历所有可能的颜色
      	  for(int j = 0 ; j < 2 ; j ++ )
      	   if(j != c){                 // 颜色必须不同
      	   	    // 遍历所有可能的数值
      	   	    for(int k = 1 ; k <= 10 ; k ++ )
      	   	     if(k != a) {           // 数值必须不同
      	   	     	 // 更新dp[i]: 从颜色为j、数值为k的最后一个位置转移过来
      	   	     	 // 如果pre[j][k]为0，说明还没有出现过该组合，dp[pre[j][k]]=0，此时dp[i]=1（新序列）
      	   	     	 // 如果pre[j][k]不为0，则可以从该位置转移，dp[i] = dp[pre[j][k]] + 1
      	   	     	 dp[i] = max(dp[i], dp[pre[j][k]] + 1);
				 }
			 }
		  
		  // 更新pre数组：记录颜色为c、数值为a的最后一个位置
		  pre[c][a] = i;
		  
		  // 更新全局答案
		  ans = max(ans, dp[i]);
	  }
	  
	  // 输出最长合法序列长度
	  cout<<ans<<"\n";
}


/**
 * 主函数
 * 处理多组测试用例
 */
signed main(){  
    // 加速输入输出
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // 读入测试用例数量
    cin >> T;
    
    // 处理每组测试用例
    while(T--){
    	solve();
	}

    return 0;
}
