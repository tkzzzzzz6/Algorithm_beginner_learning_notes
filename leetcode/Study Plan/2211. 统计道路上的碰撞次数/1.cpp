class Solution {
    public:
        int countCollisions(string directions) {
            int n = directions.size();

            int l = 0;
            while( l < n && directions[l] == 'L')
                ++l;
            int r = n;
            while(r > l && directions[r-1] == 'R')
                --r;

            int ans = 0;
            for(int i = l;i<r;++i)
            {
                if(directions[i] != 'S')
                    ++ans;
            }
            return ans;
        }
    };
