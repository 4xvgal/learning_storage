package main

import (
	"fmt"
	"math"
)

func main() {
	time := elapsed_t.ElapsedT_start()
	elapsed_t.ElapsedT_end(time)
	var t int
	var n int
	var cnt int = 0
	fmt.Scanln(&t)

	for i := 0; i < t; i++ {
		fmt.Scanln(&n)
		if isprimenumber(n) == true {
			cnt++
		}
	}
	fmt.Println(cnt)
}

func isprimenumber(n int) bool {
	if n == 1 {
		return false
	} else if n%2 == 0 {
		if n == 2 {
			return true
		} else {
			return false
		}
	}
	for i := 3; i < int(math.Sqrt(float64(n))); i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true

}
