package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

func next() string {
	sc.Scan()
	return sc.Text()
}

func nextInt() int {
	v, _ := strconv.Atoi(next())
	return v
}

func main() {
	defer out.Flush()
	sc.Split(bufio.ScanWords)
	t := 1
	// t = nextInt()
	for ; t > 0; t-- {
		solve()
	}
}

func solve() {
	n, s := nextInt(), nextInt()
	first_row := make([]int, n)
	q := s / n
	r := s % n

	// 构造第一行
	for i := 0; i < n; i++ {
		if i < r {
			first_row[i] = q + 1
		} else {
			first_row[i] = q
		}
	}

	// 构造并打印整个矩阵
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			sep := " "
			if j == n-1 {
				sep = ""
			}
			fmt.Printf("%d%s", first_row[(j-i+n)%n], sep)
		}
		fmt.Println()
	}

}
