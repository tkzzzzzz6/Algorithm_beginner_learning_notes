package main

import (
	"strings"

	"golang.org/x/tour/wc"
)

func WordCount(s string) map[string]int {
	words := strings.Fields(s)
	wordCount := make(map[string]int)
	for _,word := range words{
		wordCount[word]++

	}
	return wordCount
}

func main() {
	wc.Test(WordCount)
}
