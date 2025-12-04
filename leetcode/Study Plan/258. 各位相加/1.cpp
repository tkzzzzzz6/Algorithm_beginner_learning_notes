class Solution {
    public:
        int addDigits(int num) {
            while(num >= 10)
            {
                long long ans = 0;
                while(num >0)
                {
                    ans += num % 10;
                    num /= 10;
                }
                num = ans;
            }
            return num;
        }
    };
