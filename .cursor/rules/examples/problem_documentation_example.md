# Problem 1534: Count Good Triplets

## Problem Information
- **Platform**: LeetCode
- **ID**: 1534
- **Difficulty**: Easy
- **Tags**: Array, Enumeration, Optimization
- **URL**: https://leetcode.com/problems/count-good-triplets/
- **Solved Date**: 2023-05-15

## Problem Description
Given an array of integers `arr`, and three integers `a`, `b` and `c`, we need to count good triplets.

A triplet `(arr[i], arr[j], arr[k])` is good if the following conditions are true:
- `0 <= i < j < k < arr.length`
- `|arr[i] - arr[j]| <= a`
- `|arr[j] - arr[k]| <= b`
- `|arr[i] - arr[k]| <= c`

Return the number of good triplets.

### Input
- Array `arr` of integers where `3 <= arr.length <= 100` and `0 <= arr[i] <= 1000`
- Three integers `a, b, c` where `0 <= a, b, c <= 1000`

### Output
- An integer representing the count of good triplets

### Examples
```
Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
Output: 4
Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)]

Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
Output: 0
```

## Approach
### Intuition
- Since the constraints are small (array length up to 100), we can use brute force enumeration to check all possible triplets.
- For each triplet (i,j,k), we need to check if it satisfies all three conditions.

### Algorithm
1. Initialize a counter to 0
2. Use three nested loops to enumerate all possible triplets (i,j,k) where i < j < k
3. For each triplet, check if it satisfies all three conditions:
   - |arr[i] - arr[j]| <= a
   - |arr[j] - arr[k]| <= b
   - |arr[i] - arr[k]| <= c
4. If a triplet satisfies all conditions, increment the counter
5. Return the counter

### Optimization
- We can break the inner loops early if certain conditions are not met
- For example, if |arr[i] - arr[j]| > a, we can skip checking k values

### Complexity Analysis
- **Time Complexity**: O(n³) - We have three nested loops, each potentially iterating through O(n) elements
- **Space Complexity**: O(1) - We only use a constant amount of extra space

## Implementation

```cpp
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Check first condition early
                if (abs(arr[i] - arr[j]) <= a) {
                    for (int k = j + 1; k < n; k++) {
                        // Check remaining conditions
                        if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                            count++;
                        }
                    }
                }
            }
        }
        
        return count;
    }
};
```

## Key Learnings
- Brute force approach can be effective for problems with small constraints
- Early condition checking can optimize even brute force solutions
- The absolute value operation is important when comparing differences

## Related Problems
- LeetCode 15: 3Sum
- LeetCode 16: 3Sum Closest
- LeetCode 2179: Count Good Triplets in an Array 