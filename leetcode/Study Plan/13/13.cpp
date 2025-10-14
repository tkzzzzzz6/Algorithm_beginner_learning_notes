#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(string s) {
        // 创建一个字典，将罗马数字与对应的整数值进行映射
        std::unordered_map<char, int> roman_to_int = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        // 初始化结果和前一个字符的值
        int result = 0;
        int prev_value = 0;
        
        // 遍历字符串中的每个字符
        for (char c : s) {
            // 获取当前字符对应的整数值
            int current_value = roman_to_int[c];
            
            // 如果当前值大于前一个值，说明出现了减法情况，需要减去两倍的前一个值
            if (current_value > prev_value) {
                result += current_value - 2 * prev_value;
            } else {
                // 否则，直接将当前值加到结果中
                result += current_value;
            }
            
            // 更新前一个值为当前值
            prev_value = current_value;
        }
        
        // 返回最终结果
        return result;
    }
};