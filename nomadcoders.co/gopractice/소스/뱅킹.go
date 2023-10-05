package main

import (
	"fmt"

	"nomadcoders.co/gopractice/src/banking"
)

func main() {
	jm := banking.Newaccount("JM")
	fmt.Println(jm)
	jm.Deposit(10)
	fmt.Println("balance", jm.Balance())
	err := jm.Withdraw(20)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println("balance", jm.Balance())
}

//im horny honey
