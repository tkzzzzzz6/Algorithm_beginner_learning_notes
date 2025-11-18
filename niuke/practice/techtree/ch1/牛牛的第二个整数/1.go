package main

import (
    "fmt"
)

func main() {
	
	for i:= 0;i<2;i++{
		var x int
		fmt.Scan(&x)
		if i == 1{
			fmt.Print(x)
		}
	}
}