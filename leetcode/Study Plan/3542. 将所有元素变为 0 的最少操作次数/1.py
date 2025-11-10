class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = 0
        st = []

        for x in nums:
            while st and x < st[-1]:
                st.pop()
                ans += 1
            if not st or x != st[-1]:
                st.append(x)

        return ans + len(st) - (st[0] == 0) # 0 is not needed to be operated


