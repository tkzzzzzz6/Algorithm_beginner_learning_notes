// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    // n-输入的数，m-重排后的数
    int n, m;
    int n1, n2, n3;
    // 请在此添加代码，输入一个小于1000的正整数，重排出最大的数存入m中
    /********** Begin *********/
    scanf("%d", &n);

    n1 = n / 100;       
    n2 = (n / 10) % 10; 
    n3 = n % 10;        


    //比较n1,n2,n3的大小
    if (n1 <= n2 && n1 <= n3){
        if (n2 <= n3){
            m = n3 * 100 + n2 * 10 + n1;
        }
        else{
            m = n2 * 100 + n3 * 10 + n1;
        }
    }
    else if (n2 <= n1 && n2 <= n3){
        if (n1 <= n3){
            m = n3 * 100 + n1 * 10 + n2;
        }
        else{
            m = n1 * 100 + n3 * 10 + n2;
        }
    }
    else{
        if (n1 <= n2){
            m = n2 * 100 + n1 * 10 + n3;
        }else{
            m = n1 * 100 + n2 * 10 + n3;
        }
    }
    

    /********** End **********/
    // 输出重排后的数
    printf("%d\n", m);
    return 0;
}