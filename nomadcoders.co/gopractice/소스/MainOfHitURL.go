package main

import (
	"errors"
	"fmt"
	"net/http"
)

//errRequestFailed 에러 변수 used at func hitURL
var errRequestFailed = errors.New("Request failed")

func main() {
	//results is map
	var results = make(map[string]string)

	urls := []string{
		"https://www.airbnb.com",
		"https://www.google.com",
		"https://www.amazon.com",
		"https://www.reddit.com",
		"https://soundcloud.com",
		"https://www.facebook.com",
		"https://www.instagram.com",
		"https://academy.nomadcoders.co/",
	}
	//put result to results map
	for _, url := range urls {
		//result 기본 결과 값
		result := "OK"
		//err 변수에 hitURL의 반환값 저장
		err := hitURL(url)
		//만약 에러가 nil 일 경우 FAILED
		if err != nil {
			result = "FAILED"
		}
		//해당 사항이 없을 시 result를 result[url] 맵에 저장
		results[url] = result
	}
	//결과 값 출력
	for url, result := range results {
		fmt.Println(url, result)
	}
}
func hitURL(url string) error {
	fmt.Println("Checking:", url)
	//resp = http.Response
	resp, err := http.Get(url)
	if err != nil || resp.StatusCode >= 400 {
		fmt.Println(err, resp.StatusCode)
		return errRequestFailed
	}
	return nil
}
