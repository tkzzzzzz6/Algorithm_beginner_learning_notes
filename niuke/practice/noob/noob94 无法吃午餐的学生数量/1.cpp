/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-07 11:05:51
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-07 11:19:07
 */
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
    *
    *
    * @param students int整型vector
    * @param sandwiches int整型vector
    * @return int整型
    */
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
    int cnt1 = 0, cnt0 = 0, ans = 0;
    for (auto s : students) {
        if (s == 0)
        ++cnt0;
        else
        ++cnt1;
    }

    for (int i = 0; i < (int)sandwiches.size(); ++i) {
        if (sandwiches[i] == 0) {
        if (cnt0 == 0)
            return (int)sandwiches.size() - i;
        --cnt0;
        } else {
        if (cnt1 == 0)
            return (int)sandwiches.size() - i;
        --cnt1;
        }
    }
    return 0;
    }
};
