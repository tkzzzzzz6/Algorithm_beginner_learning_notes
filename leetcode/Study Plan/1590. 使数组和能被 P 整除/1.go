func minSubarray(nums []int, p int) int {
    x := 0
	for _,v := range nums{
		x+=v
	}
	x%=p
	if x == 0{
		return 0
	}
	n := len(nums)
	ans,s := n,0
	last := map[int]int{s:-1}
	for i,v := range nums{
		s += v
		last[s%p] = i
		if j,ok := last[(s-x+p)%p];ok{
			ans = min(ans,i-j)
		}
	}
	if ans < n{
		return ans
	}
	return -1
}
