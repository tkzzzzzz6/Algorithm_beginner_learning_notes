/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-31 01:16:23
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-31 01:16:35
 */
func numIdenticalPairs(nums []int) int {
    cnt := map[int]int{}
	for _,x := range nums {
		// x = nums[j]
		
		ans += cnt[x]
		cnt[x]++
	}
	return
}
