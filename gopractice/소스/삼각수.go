package main

import "fmt"

func triSequence(triOverK int) int {
	triSum := 0
	triMeasure := 0
	for i := 1; ; i++ {
		triSum += i
		triMeasure = 0
		for j := 1; j <= triSum; j++ {
			if triSum%j == 0 {
				triMeasure++
			}
		}
		if triMeasure >= triOverK {
			return triSum
		}
	}
}

func main() {
	var triOverK int
	fmt.Scanln(&triOverK)
	fmt.Println(triSequence(triOverK))
}
