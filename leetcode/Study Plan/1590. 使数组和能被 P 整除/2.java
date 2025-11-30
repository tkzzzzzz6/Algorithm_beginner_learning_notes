class Solution {
    public int minSubarray(int[] nums, int p) {
        int x = 0;
        for(int num:nums)
        {
            x = (x+num)%p;
        }
        if(x == 0)
        {
            return 0;
        }
        Map<Integer,Integer> index = new HashMap<Integer,Integer>();
        int y = 0,res = nums.length;
        for(int i = 0;i<nums.length;i++)
        {
            index.put(y,i);
            y = (y+nums[i])%p;
            if(index.containsKey((y-x+p)%p))
            {
                res = Math.min(res,i-index.get((y-x+p)%p)+1);
            }
        }
        return res < nums.length ? res : -1;
    }
}
