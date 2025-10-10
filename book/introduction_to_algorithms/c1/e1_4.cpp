#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

// 鸡兔同笼 number-n,leg-m
// a+b = n
// 2a+4b = m
int main() {
    int n,m;
    // scanf()返回成功读取并赋值的变量个数
    while(scanf("%d%d",&n,&m)==2)
    {
        int a = (4*n-m)/2,b=(m-2*n)/2;
        if(a<0||b<0||m%2==1)printf("No answer\n");
        else printf("%d %d\n",a,b);
    }
    return 0;
}
