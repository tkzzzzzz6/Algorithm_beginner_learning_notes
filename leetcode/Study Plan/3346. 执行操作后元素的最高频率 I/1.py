import bisect  # ֲģ飬ڿٲеĲλ

class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        """
        ⣺ numsԽ numOperations β
        ÿβԽԪ +k  -k
        гƵߵֵƵ

        ˼·
        1. ͳԭÿֵĳִ
        2. öÿܵĿֵжֿͨ
        3. Ŀֵ iΧ [i-k, i+k] ڵֶԱ i
        """

        # һ飬ںֲҺͳ
        nums.sort()

        # ans: ¼մ𰸣Ƶʣ
        ans = 0

        # num_count: ֵ䣬key=֣value=ԭгֵĴ
        # 磺nums=[1,1,2,2,2,3]  num_count={1:2, 2:3, 3:1}
        num_count = {}

        # last_num_index: ¼ǰͳƵֵʼλ
        last_num_index = 0

        #  ͳԭÿֵĳִ
        for i in range(len(nums)):
            # ǰһֲͬͬµ֣
            if nums[i] != nums[last_num_index]:
                # һִֵּ
                # ִ = ǰ - ʼ
                num_count[nums[last_num_index]] = i - last_num_index

                # ´𰸣ԭеƵ
                ans = max(ans, i - last_num_index)

                # ʼΪǰλãʼͳµ
                last_num_index = i

        # ѭ󣬴һ֣Ϊѭֻ"ͬ"
        num_count[nums[last_num_index]] = len(nums) - last_num_index
        ans = max(ans, len(nums) - last_num_index)

        #  öпܵĿֵ
        # СֵֵöÿܳΪĿ
        # ΪʲôΧΪֻ +k  -kΧĿֵܱ
        for i in range(nums[0], nums[-1] + 1):

            #  ʹöֲҵ [i-k, i+k] Χڵ

            # bisect_left: ҵһ >= (i-k) Ԫλ
            # l ǷΧ߽
            l = bisect.bisect_left(nums, i - k)

            # bisect_right: ҵһ > (i+k) Ԫλ
            # r ǷΧұ߽1Ϊ bisect_right ص""λã
            r = bisect.bisect_right(nums, i + k) - 1

            #  [l, r] ڵֶͨһβ i
            # Ϊ i Ĳ඼ <= k

            #  ѡ i ΪĿֵʱƵ

            if i in num_count:
                # 1i ԭд

                # num_count[i]: i ԭеҪ
                # r - l + 1: ܹжٸ
                # numOperations: Բٴ

                # ԣȱԭе iȻֽв
                # ܳ numOperations
                # ܳڵ
                temp_ans = min(r - l + 1, num_count[i] + numOperations)

                # ͣ
                # -  num_count[i] + numOperations >= r-l+1˵㹻԰ֶ i
                # - ֻܱ num_count[i] + numOperations

            else:
                # 2i ԭв

                # ûԭ iҪ 0 ʼ
                #  numOperations
                # Ҳܳڵ
                temp_ans = min(r - l + 1, numOperations)

                # ͣ
                # -  numOperations >= r-l+1԰ֶ i
                # - ֻܱ numOperations

            # ȫŴ
            ans = max(ans, temp_ans)

        # Ƶ
        return ans
