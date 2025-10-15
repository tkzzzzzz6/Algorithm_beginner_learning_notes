class Solution
{
public:
    string addBinary(string a, string b)
    {
        int len_a = a.size();
        int len_b = b.size();
        int max_len = max(len_a, len_b);
        string result = "";
        int carry = 0;
        for (int i = 0; i < max_len; i++)
        {
            int bit_a = i < len_a ? a[len_a - i - 1] - '0' : 0;
            int bit_b = i < len_b ? b[len_b - i - 1] - '0' : 0;
            int sum = bit_a + bit_b + carry;
            result = to_string(sum % 2) + result;
            carry = sum / 2;
        }
        if (carry > 0)
        {
            result = to_string(carry) + result;
        }
        return result;
    }
};