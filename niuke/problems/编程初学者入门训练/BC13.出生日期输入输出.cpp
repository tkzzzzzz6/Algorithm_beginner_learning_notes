/*
 * @Author: tkzzzzzz6
 * @Date: 2026-08-13 18:51:32
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-08-13 18:56:42
 */
/**
 * @nc app=nowcoder id=4a4a9dd1edb6453ba4a0432319200743 topic=290 question=275034 lang=C++
 * 2026-08-13 18:51:32
 * https://www.nowcoder.com/practice/4a4a9dd1edb6453ba4a0432319200743?tpId=290&tqId=275034
 * [BC13] 出生日期输入输出
 */

/** @nc code=start */

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int year, month, date;
    scanf("%4d%2d%2d", &year, &month, &date);
    printf("year=%d\n", year);
    printf("month=%02d\n", month);
    printf("date=%02d\n", date);
}
// 64 位输出请用 printf("%lld")

/** @nc code=end */
