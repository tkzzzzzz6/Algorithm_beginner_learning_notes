/**
 * @nc app=nowcoder id=741a9b79fabe474cb153a49b4bff5828 topic=225 question=2180560 lang=C++
 * 2026-05-04 16:28:11
 * https://www.nowcoder.com/practice/741a9b79fabe474cb153a49b4bff5828?tpId=225&tqId=2180560
 * [CPP11] 判断季节
 */

/** @nc code=start */

#include <iostream>
using namespace std;

int main() {
    
    int month;
    cin >> month;

    // write your code here......
    switch(month){
        case 3:case 4:case 5:
            cout << "春季" << endl;
            break;
        case 6:case 7:case 8:
            cout << "夏季" << endl;
            break;
        case 9:case 10:case 11:
            cout << "秋季" << endl;
            break;
        case 12:case 1:case 2:
            cout << "冬季" << endl;
            break;
        default:
            cout << "不合法" << endl;
            break;
    }

    return 0;
}

/** @nc code=end */
