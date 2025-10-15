// f(x) = x^2 - C
// f'(x) = 2x

// f(x) = 0 的解为 x = sqrt(C)
// f(x) ~= f(x0) + f'(x0)(x - x0)
//  0 = x0^2 - C + 2x0(x - x0)
//  x = (C - x0^2) / 2x0 + x0 = (x0 + C / x0) / 2

class Solution
{
public:
    int mySqrt(int x)
    {
        if(x == 0)
            return 0;
        long x0 = x;
        while(x0 * x0 > x){
            x0 = (x0 + x / x0) / 2;
        }
        return (int)x0;
    }
};