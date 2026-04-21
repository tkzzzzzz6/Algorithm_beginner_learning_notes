class Solution:
    def hasSameDigits(self, s: str) -> bool:
        n = len(s)

        # ַתΪб޸
        # : "1234" -> ['1', '2', '3', '4']
        s_list = list(s)

        # ѭѹ
        # 1: n-1Ԫ (ѹ1)
        # 2: n-2Ԫ (ѹ2)
        # ...
        # n-2: 2Ԫ (ʣ2)
        for i in range(1, n - 1):
            # ڲѭڵǰУڵֶ
            # iҪ n-i
            for j in range(n - i):

                # chr() ASCIIתַ
                s_list[j] = chr((int(s_list[j]) + int(s_list[j+1])) % 10)

        #  n-2 ѹֻʣ2
        # жǷͬ
        return s_list[0] == s_list[1]

