class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)

        pre_max = [0]*n
        pre_max[0] = height[0]
        for i in range(1,n,1):
            pre_max[i] = max(pre_max[i-1],height[i])

        suf_max = [0]*n
        suf_max[-1] = height[-1]
        for i in range(n-2,-1,-1):
            suf_max[i] = max(suf_max[i+1],height[i])

        ans = 0
        # for i in range(1,n):
        #     capacity = min(pre_max[i],suf_max[i]) 
        #     if capacity - height[i] > 0:
        #         ans += capacity - height[i]

        for pre,suf,h in zip(pre_max,suf_max,height):
            ans += min(pre,suf)-h

        return ans