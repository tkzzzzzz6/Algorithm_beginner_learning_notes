func findFinalValue(nums []int, original int) int {
	n := original
	sort.Ints(nums)
	for _,v := range nums{
		if v == n{
			n*=2
		}
	}
	return n
}