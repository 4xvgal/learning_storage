package main

import (
	"fmt"
	"runtime"
)

func main() {
	//noc is "number of cpus"
	noc := runtime.NumCPU()
	//func use multiple cpus each "number of cpus"
	runtime.GOMAXPROCS(noc)
	fmt.Println("number of cpus", noc)
	c := make(chan string)
	people := [5]string{"JM", "SM", "JJ", "HJ", "EO"}

	for _, person := range people {
		go isSexy(person, c)
	}
	//number of routines is how much go routines running
	fmt.Println("number of routines:", runtime.NumGoroutine())
	for i := 0; i < len(people); i++ {
		fmt.Println(<-c)
	}
}

func isSexy(person string, c chan string) {
	//time.Sleep(time.Second * 1)
	c <- person + " is sexy"
}
