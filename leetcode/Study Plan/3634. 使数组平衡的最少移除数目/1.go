func minRemoval(nums []int, k int) int {
	slices.Sort(nums)
	max_save, left := 0, 0
	for i, mx := range nums {
		for nums[left]*k < mx {
			left++
		}
		max_save = max(max_save, i-left+1)
	}
	return len(nums) - max_save
}
