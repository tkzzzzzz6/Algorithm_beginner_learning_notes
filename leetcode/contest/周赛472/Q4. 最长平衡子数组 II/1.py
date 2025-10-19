class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        
        # ������ܵĳ��ȿ�ʼö��
        for length in range(n, 0, -1):
            # ö�����г���Ϊlength��������
            for i in range(n - length + 1):
                even_set = set()
                odd_set = set()
                
                # ͳ��������[i, i+length-1]
                for j in range(i, i + length):
                    if nums[j] % 2 == 0:
                        even_set.add(nums[j])
                    else:
                        odd_set.add(nums[j])
                
                # �ҵ�ƽ�������飬��������
                if len(even_set) == len(odd_set):
                    return length
        
        