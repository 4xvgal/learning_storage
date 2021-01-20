package main

import (
	"fmt"

	"nomadcoders.co/gopractice/src/mydict"
)

func main() {
	//dictonary는 mydict 패키지의 map을 받아온다
	dictonary := mydict.Dictionary{}
	//word 단어
	word := "hello"
	//definition 단어의 뜻
	definition := "Greeting"
	//에러 변수
	//mydict의 Add 함수실행
	//인자 word, definition, 리턴 값 err에 저장
	err := dictonary.Add(word, definition)
	if err != nil { //에러가 있을경우 err 변수에 저장된 리턴값 출력
		fmt.Println(err)
	}
	//같은 word, definition에 이미 있는지 확인
	hello, _ := dictonary.Search(word)
	fmt.Println("Found", word, "Definition", hello)
	err2 := dictonary.Add(word, definition)
	if err2 != nil {
		fmt.Println(err2)
	}

}
