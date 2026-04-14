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
                # ַתΪ
                # ord('0') = 48, ord('1') = 49, ..., ord('9') = 57
                #  ord(ַ) - ord('0') õʵֵ
                digit1 = ord(s_list[j]) - ord('0')      # ǰ
                digit2 = ord(s_list[j + 1]) - ord('0')  # һ

                # Ӳȡģ10ֻλ
                # Ȼתַ洢
                # chr() ASCIIתַ
                s_list[j] = chr(((digit1 + digit2) % 10) + ord('0'))

        #  n-2 ѹֻʣ2
        # жǷͬ
        return s_list[0] == s_list[1]

