func longestConsecutive(nums []int) int {
	numset := make(map[int]bool)
	for _,v := range nums{
		numset[v] = true
	}
	ans := 0
	for x := range numset{
		_,existsPrev := numset[x-1]
		if existsPrev{
			continue
		}
		currentNum := x
		currentLength := 1
		for{
			_,existsNext := numset[currentNum+1]
			if !existsNext{
				break
			}
			currentNum++
			currentLength++
		}
		ans = max(ans,currentLength)
	}
	return ans
}

// func max(a,b int)int{
// 	if a > b{
// 		return a
// 	}else{
// 		return b
// 	}
// }
