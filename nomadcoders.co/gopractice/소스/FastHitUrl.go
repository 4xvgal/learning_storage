package main

import (
	"errors"
	"fmt"
	"log"
	"net/http"
	"time"
)

//errRequestFailed 에러 변수 used at func hitURL
var errRequestFailed = errors.New("Request failed")

type requestResult struct {
	url    string
	status string
}

func main() {
	//start time tracking
	start := time.Now()
	//result is a map that save the
	results := make(map[string]string)
	c := make(chan requestResult)
	urls := []string{
		"https://www.airbnb.com",
		"https://www.google.com",
		"https://www.amazon.com",
		"https://www.reddit.com",
		"https://soundcloud.com",
		"https://www.naver.com",
		"https://comic.naver.com",
		"https://www.duckduckgo.com",
		"https://www.apple.com",
		"https://pornhub.com",
		"https://code.visualstudio.com",
		"https://nomadcoders.co",
		"https://youtube.com",
		"https://facebook.com",
		"https://amazon.com",
		"https://office.com",
	}
	//put result to results map
	for _, url := range urls {
		go hitURL(url, c)
	}
	for i := 0; i < len(urls); i++ {
		result := <-c
		results[result.url] = result.status
	}
	for url, status := range results {
		fmt.Println(url, status)
	}
	timeTrack(start, "main.go")
}
func hitURL(url string, c chan requestResult) {
	resp, err := http.Get(url)
	status := "OK"
	if err != nil || resp.StatusCode >= 400 {
		status = "FAILED"
	}
	c <- requestResult{url: url, status: status}
}
func timeTrack(start time.Time, name string) {
	elapsed := time.Since(start)
	log.Printf("%s took %s", name, elapsed)
}
