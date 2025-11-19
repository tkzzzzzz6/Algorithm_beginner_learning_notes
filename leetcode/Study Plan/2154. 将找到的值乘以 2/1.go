func findFinalValue(nums []int, original int) int {
	st := make(map[int]bool)
	for _,v := range nums{
		st[v] = true
	}

	n := original
	for st[n]{
		n *= 2
	}

	return n
}