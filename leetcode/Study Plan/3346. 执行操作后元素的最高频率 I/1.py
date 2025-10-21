import bisect  # ������ֲ���ģ�飬���ڿ��ٲ������������еĲ���λ��

class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        """
        ���⣺�������� nums�����Խ������ numOperations �β���
        ÿ�β������Խ�����Ԫ�� +k �� -k
        ������������г���Ƶ����ߵ����ֵ�Ƶ��
        
        ˼·��
        1. ��ͳ��ԭ������ÿ�����ֵĳ��ִ���
        2. ö��ÿ�����ܵ�Ŀ��ֵ�������ж������ֿ���ͨ�����������
        3. ����Ŀ��ֵ i����Χ [i-k, i+k] �ڵ����ֶ����Ա�� i
        """
        
        # ��һ�����������飬���ں������ֲ��Һ�ͳ��
        nums.sort()
        
        # ans: ��¼���մ𰸣����Ƶ�ʣ�
        ans = 0
        
        # num_count: �ֵ䣬key=���֣�value=��������ԭ�����г��ֵĴ���
        # ���磺nums=[1,1,2,2,2,3] �� num_count={1:2, 2:3, 3:1}
        num_count = {}
        
        # last_num_index: ��¼��ǰ����ͳ�Ƶ����ֵ���ʼ����λ��
        last_num_index = 0
        
        #  ͳ��ԭ������ÿ�����ֵĳ��ִ��� 
        for i in range(len(nums)):
            # �����ǰ��������һ����ͬ���ֲ�ͬ���������µ����֣�
            if nums[i] != nums[last_num_index]:
                # ����һ�����ּ�����ִ��������ֵ�
                # ���ִ��� = ��ǰ���� - ��ʼ����
                num_count[nums[last_num_index]] = i - last_num_index
                
                # ���´𰸣�ԭ���������е����Ƶ��
                ans = max(ans, i - last_num_index)
                
                # ������ʼ����Ϊ��ǰλ�ã���ʼͳ���µ�����
                last_num_index = i
        
        # ѭ�������󣬴������һ�����֣���Ϊѭ����ֻ������"��ͬ"�������
        num_count[nums[last_num_index]] = len(nums) - last_num_index
        ans = max(ans, len(nums) - last_num_index)
        
        #  ö�����п��ܵ�Ŀ��ֵ 
        # ����Сֵ�����ֵ��ö��ÿ�����ܳ�ΪĿ�������
        # Ϊʲô�������Χ����Ϊ����ֻ�� +k �� -k�����������Χ��Ŀ��ֵ�������������ܱ����
        for i in range(nums[0], nums[-1] + 1):
            
            #  ʹ�ö��ֲ����ҵ� [i-k, i+k] ��Χ�ڵ����� 
            
            # bisect_left: �ҵ���һ�� >= (i-k) ��Ԫ��λ��
            # l �Ƿ�Χ��߽������
            l = bisect.bisect_left(nums, i - k)
            
            # bisect_right: �ҵ���һ�� > (i+k) ��Ԫ��λ��
            # r �Ƿ�Χ�ұ߽����������1����Ϊ bisect_right ���ص���"����"��λ�ã�
            r = bisect.bisect_right(nums, i + k) - 1
            
            # ���� [l, r] �ڵ��������ֶ�����ͨ��һ�β������ i
            # ��Ϊ������ i �Ĳ�඼ <= k
            
            #  ����ѡ�� i ��ΪĿ��ֵʱ�����Ƶ�� 
            
            if i in num_count:
                # ���1��i ������ԭ�����д���
                
                # num_count[i]: i ԭ�����е�����������Ҫ������
                # r - l + 1: �������ܹ��ж��ٸ�����
                # numOperations: �����Բ������ٴ�
                
                # ���ԣ����ȱ���ԭ�е� i��Ȼ����������������ֽ��в���
                # �������������ܳ��� numOperations
                # ���������ܳ��������ڵ�������
                temp_ans = min(r - l + 1, num_count[i] + numOperations)
                
                # ���ͣ�
                # - ��� num_count[i] + numOperations >= r-l+1��˵�����������㹻�����԰��������������ֶ���� i
                # - ����ֻ�ܱ�� num_count[i] + numOperations ��
                
            else:
                # ���2��i ������ԭ�����в�����
                
                # û��ԭ���� i��������Ҫ�� 0 ��ʼ����
                # ������ numOperations ��
                # ��Ҳ���ܳ��������ڵ�������
                temp_ans = min(r - l + 1, numOperations)
                
                # ���ͣ�
                # - ��� numOperations >= r-l+1�����԰��������������ֶ���� i
                # - ����ֻ�ܱ�� numOperations ��
            
            # ����ȫ�����Ŵ�
            ans = max(ans, temp_ans)
        
        # �������Ƶ��
        return ans