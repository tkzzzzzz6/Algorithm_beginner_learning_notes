class Solution {
    public:
    
        int countOdds(int low, int high) {
            return pre(high) - pre(low-1);
        }
        int pre(int x)
        {
            return ( x+1) >> 1; 
        }
    };
