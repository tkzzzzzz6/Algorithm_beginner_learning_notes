package main

import (
	"fmt"
	"sort"
)

func main() {
	var t int
	fmt.Scan(&t)

	for ; t > 0; t-- {
		var n int
		fmt.Scan(&n)

		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}

		sort.Ints(a)
		hasDuplicate := false
		for i := 1; i < n; i++ {
			if a[i] == a[i-1] {
				hasDuplicate = true
				break
			}
		}

		if hasDuplicate {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
