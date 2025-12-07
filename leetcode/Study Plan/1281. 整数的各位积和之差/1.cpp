class Solution {
    public:
        int subtractProductAndSum(int n) {
            long long digit_sum = 0;
            long long digit_multiply = 1;
            int flag = 0;
            while(n > 0){
                int digit = n % 10;
                if(digit == 0){
                    flag = 1;
                }
                digit_sum += digit;
                digit_multiply *= digit;
                n /= 10;
            }
            if(flag == 1){
                return -digit_sum;
            }
            return digit_multiply - digit_sum;
        }
    };
