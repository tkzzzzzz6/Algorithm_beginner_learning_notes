/**
 * @nc app=nowcoder id=d7d48b7b44df46889137ec19d924bb14 topic=225 question=2180072 lang=C++
 * 2026-05-04 16:25:05
 * https://www.nowcoder.com/practice/d7d48b7b44df46889137ec19d924bb14?tpId=225&tqId=2180072
 * [CPP7] 获取三个数中的最大值（三元表达式实现）
 */

/** @nc code=start */

#include <iostream>
using namespace std;

int main() {
    
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    // write your code here......
    cout << ((a > b) ? ((a > c) ? a : c) : ((b>c)?b:c));

    return 0;
}

/** @nc code=end */
