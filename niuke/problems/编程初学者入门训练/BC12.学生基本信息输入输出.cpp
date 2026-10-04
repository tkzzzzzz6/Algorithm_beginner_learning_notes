/*
 * @Author: tkzzzzzz6
 * @Date: 2026-08-13 18:34:18
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-08-13 18:50:32
 */
/**
 * @nc app=nowcoder id=58b6a69b4bf943b49d2cd3c15770b9fd topic=290 question=274662 lang=C++
 * 2026-08-13 18:34:18
 * https://www.nowcoder.com/practice/58b6a69b4bf943b49d2cd3c15770b9fd?tpId=290&tqId=274662
 * [BC12] 学生基本信息输入输出
 */

/** @nc code=start */

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const float eps = 1e-9;

int main() {
    int i;
    double a, b, c;
    scanf("%d;%lf,%lf,%lf", &i, &a, &b, &c);
    a += eps;
    b += eps;
    c += eps;
    // 按固定格式输出，保留两位小数
    printf("The each subject score of No. %d is %.2f, %.2f, %.2f.\n", i, a, b, c);
}
// 64 位输出请用 printf("%lld")

/** @nc code=end */
