// 模拟
func countCollisions(directions string) int {
	ans := 0
	flag := -1
	for _,c := range directions{
		if c == 'L'{
			if flag >= 0{
				ans += flag + 1
				flag = 0
			}
		}else if c == 'S'{
			if flag > 0{
				ans += flag
			}
			flag = 0
		}else{
			if flag >= 0{
				flag++
			}else{
				flag = 1
			}
		}
	}
	return ans
}
