class Solution:
    def romanToInt(self, s: str) -> int:
        # Create a dictionary to map Roman numerals to their corresponding integer values
        roman_to_int = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        
        # Initialize the result variable to store the converted integer value
        result = 0
        
        # Get the length of the input string
        n = len(s)
        
        # Iterate through each character in the input string
        for i in range(n):
            # If the current value is less than the next value, subtract it from the result
            if i < n - 1 and roman_to_int[s[i]] < roman_to_int[s[i + 1]]:
                result -= roman_to_int[s[i]]
            else:
                # Otherwise, add it to the result
                result += roman_to_int[s[i]]
        
        # Return the final result
        return result
