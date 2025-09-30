// 变量交换
#include <iostream>

using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int &a,int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}

// 利用异或运算"任何数与自己异或得0，与0异或得自己"的特性，通过三次异或操作巧妙地实现两个数的交换。
void swap3(int &a,int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}
