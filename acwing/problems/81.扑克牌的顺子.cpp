/*
 * @acwing app=acwing.cn id=77 lang=C++
 *
 * 81. 扑克牌的顺子
 */

// @acwing code start

class Solution {
   public:
    bool isContinuous(vector<int> numbers) {
        // 排除不合法数据
        if (numbers.size() < 5)
            return false;

        // 排序
        sort(numbers.begin(), numbers.end());

        // 去除0(大小王)
        int i = 0;
        while (i < numbers.size() && !numbers[i])
            ++i;
        // 出现重复不是顺子
        for (int j = i + 1; j < numbers.size(); ++j) {
            if (numbers[j] == numbers[j - 1])
                return false;
        }

        // 去除大小王之后差值应该小于 4
        return (numbers.back() - numbers[i]) <= 4;
    }
};
// @acwing code end
