class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        int sum = 0;
        int sub_arr_length = 1;
        while (sub_arr_length <= n)
        {
            for (int i = 0; i < n - sub_arr_length + 1; i++)
            {
                for (int j = i; j < i + sub_arr_length; j++)
                {
                    sum += arr[j];
                }
            }
            sub_arr_length += 2;
        }
        return sum;
    }
};