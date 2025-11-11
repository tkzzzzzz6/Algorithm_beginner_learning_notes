package main

import (
	"fmt"
)

func main() {
	var t int
	fmt.Scan(&t)

	for ; t > 0; t-- {
		var n int
		fmt.Scan(&n)

		p := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&p[i])
		}

		var x string
		fmt.Scan(&x)

		var ops [][2]int
		for i := 0; i < n; {
			if x[i] == '1' {
				j := i
				for j < n && x[j] == '1' {
					j++
				}
				ops = append(ops, [2]int{i + 1, j})
				i = j
			} else {
				i++
			}
		}

		if len(ops) > 5 {
			fmt.Println(-1)
		} else {
			fmt.Println(len(ops))
			for _, op := range ops {
				fmt.Println(op[0], op[1])
			}
		}
	}
}
