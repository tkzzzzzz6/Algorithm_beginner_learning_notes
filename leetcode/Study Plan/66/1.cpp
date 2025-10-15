class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int len = digits.size();
        // 从后往前遍历,如果当前位是9,则将当前位设置为0,继续遍历
        for (int i = len - 1; i >= 0; i--)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i] += 1;
                return digits;
            }
        }
        // 如果所有位都是9,则在开头插入1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};