package main

import (
	"fmt"

	"nomadcoders.co/gopractice/src/mydict"
)

func main() {
	dictionary := mydict.Dictionary{"first": "First Word"} //mydict 패키지의 map Dictonary를 변수에 저장
	//definition 과 err는 반환값 저장
	//mydict 패키지의 Search 함수에서 "second" 를 검색
	//키를 찾으면 값을 반환 (Key - Value)
	definition, err := dictionary.Search("second")
	//에러 핸들링
	//에러 변수가 nil (null) 이 아니라면 반환된 err를 출력
	//아닐경우 difinition에 저장된 Value 를 출력
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println(definition)
	}
}
