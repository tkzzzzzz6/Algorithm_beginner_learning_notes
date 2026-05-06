/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-04 16:37:40
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-06 22:36:29
 */
/**
 * @nc app=nowcoder id=9a2d212d23f5436c80607d5e68c6d12a topic=291 question=2185204 lang=C++
 * 2026-05-04 16:37:40
 * https://www.nowcoder.com/practice/9a2d212d23f5436c80607d5e68c6d12a?tpId=291&tqId=2185204
 * [CC1] 获取字符串长度
 */

/** @nc code=start */


#include <stdio.h>

int main() {

    char buf[100] = {};
    if(fgets(buf,sizeof(buf),stdin) == nullptr)return 0;

    char* p = buf;
    int len = 0;
    while (*p != '\0' && *p != '\n') {
        len++;
        p++;
    }

    printf("%d", len);
    return 0;
}

/** @nc code=end */
