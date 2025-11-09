# CodeForces Round #826 (Div. 3) - 2022-10-11

## Contest Overview
- **Platform**: CodeForces
- **Duration**: 2 hours
- **Number of Problems**: 7 (A-G)
- **My Rank**: 1245/21378
- **Problems Solved**: 4/7

## Problem Breakdown

### Problem A: Compare T-Shirt Sizes
- **Difficulty**: Easy
- **Tags**: Implementation, Strings
- **Time to Solve**: 8 minutes
- **Attempts**: 1
- **Approach**: Created a mapping of sizes to numeric values (S < M < L) and compared them, accounting for the number of X's as modifiers.
- **Key Challenges**: Ensuring the correct ordering between sizes with different numbers of X's.
- **Lessons Learned**: Simple mapping techniques can transform string comparison problems into numeric comparisons.

### Problem B: Funny Permutation
- **Difficulty**: Easy
- **Tags**: Constructive Algorithms, Math
- **Time to Solve**: 15 minutes
- **Attempts**: 2
- **Approach**: Constructed a permutation where each element is at least 2 positions away from its original position, with special handling for n=3.
- **Key Challenges**: The case n=3 required special handling as it's impossible to create a valid permutation.
- **Lessons Learned**: Always check edge cases, especially small input values that might have special properties.

### Problem C: Minimal Distance
- **Difficulty**: Medium
- **Tags**: Greedy, Sorting
- **Time to Solve**: 25 minutes
- **Attempts**: 1
- **Approach**: Grouped pairs of elements with the same color, then minimized the sum of distances between pairs.
- **Key Challenges**: Understanding how to optimally pair elements of the same color to minimize distance.
- **Lessons Learned**: Sorting by color first, then optimizing within each color group, can be an effective strategy.

### Problem D: Masha and a Beautiful Tree
- **Difficulty**: Medium
- **Tags**: Divide and Conquer, Recursion
- **Time to Solve**: 40 minutes
- **Attempts**: 3
- **Approach**: Used a recursive divide-and-conquer approach to sort the tree with minimum swaps.
- **Key Challenges**: Handling the case where it's impossible to sort the tree with valid operations.
- **Lessons Learned**: Recursive approaches are powerful for tree-related problems, especially those involving operations at each level.

### Problem E: Sending a Sequence Over the Network
- **Difficulty**: Medium-Hard
- **Tags**: Dynamic Programming
- **Time to Solve**: Not solved during contest
- **Key Challenges**: Formulating the correct DP state and transitions for this problem.
- **Post-Contest Solution**: Created a DP array where dp[i] is true if the sequence up to position i can be sent. For each position i, we check if we can add the current element as a length or a sequence.

### Problem F: Smaller
- **Difficulty**: Hard
- **Tags**: Binary Search, Data Structures
- **Time to Solve**: Not solved during contest
- **Key Challenges**: Understanding the problem's constraints and efficient calculation of lexicographically smallest strings.

### Problem G: Balanced Brackets
- **Difficulty**: Hard
- **Tags**: Constructive Algorithms, Greedy
- **Time to Solve**: Not solved during contest
- **Key Challenges**: Determining the optimal strategy for placing brackets to maximize the balance.

## Overall Performance Analysis
- **Strengths**:
  - Quick implementation of easy problems
  - Good understanding of sorting and greedy approaches
  - Successful application of divide-and-conquer techniques

- **Weaknesses**:
  - Struggled with harder dynamic programming problems
  - Need to improve on more complex data structure usage
  - Time management could be better for harder problems

- **Time Management**:
  - Reading: 15 minutes
  - Thinking: 35 minutes
  - Coding: 50 minutes
  - Debugging: 20 minutes

## Key Takeaways
1. Always validate solutions with small test cases, especially for constructive algorithm problems
2. Consider edge cases early in the solution development process
3. For tree-based problems, recursive approaches often provide elegant solutions
4. When stuck, try to break down the problem into smaller, manageable subproblems

## Action Items for Next Contest
1. Practice more dynamic programming problems, especially those involving sequences
2. Review advanced data structures useful for competitive programming (segment trees, fenwick trees)
3. Improve time management by setting strict time limits for each problem
4. Create a cheat sheet for common algorithms and their implementations for quick reference during contests 