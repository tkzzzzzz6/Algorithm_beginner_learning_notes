class Solution {
    public int countPartitions(int[] nums) {
        int sum = Arrays.stream(nums).sum();
        return sum % 2 != 0 ? 0 : nums.length - 1;       
    }
}
