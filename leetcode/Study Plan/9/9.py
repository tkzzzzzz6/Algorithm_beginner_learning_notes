class Solution:
    def isPalindrome(self, x: int) -> bool:
        str_x = str(x)
        reversed_str_x = str_x[::-1]
        if reversed_str_x == str_x:
            return True
        else:
            return False